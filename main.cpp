#include "ast.hpp"
#include "error.hpp"
#include "genee.hpp"
#include "parser.tab.hpp"
#include "eeoptim.hpp"
#include "eeast.hpp"
#include "gentg.hpp"
#include "tgoptim.hpp"

#include <iostream>
#include <fstream>
#include <cstring>

enum class WorkingMode {
    EEMODE = 0,
    TGMODE = 1,
    RVMODE = 2,
};

extern FILE *yyin, *yyout;

static inline void PrintHelpInfo(const char *p);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        PrintHelpInfo(argv[0]);
        exit(-1);
    }

    // parse params
    WorkingMode mode;
    char *infile = nullptr, *outfile = nullptr;
    for (int i = 1; i < argc; ++i) {
        if (!strcmp(argv[i], "-S")) {
            if (i == argc - 1) break;
            if (argv[i + 1][0] != '-') {
                infile = argv[i + 1];
                mode = WorkingMode::RVMODE;
            }
        } else if (!strcmp(argv[i], "-t")) {
            if (i == argc - 1) break;
            if (argv[i + 1][0] != '-') {
                infile = argv[i + 1];
                mode = WorkingMode::TGMODE;
            }
        } else if (!strcmp(argv[i], "-e")) {
            if (i == argc - 1) break;
            if (argv[i + 1][0] != '-') {
                infile = argv[i + 1];
                mode = WorkingMode::EEMODE;
            }
        } else if (!strcmp(argv[i], "-o")) {
            if (i == argc - 1) break;
            if (argv[i + 1][0] != '-')
                outfile = argv[i + 1];
        } else if (!strcmp(argv[i], "-h")) {
            PrintHelpInfo(argv[0]);
            exit(-1);
        }
    }

    if (!infile)
        Reporterror(Error::Noinputfile);

    FILE *file;
    file = fopen(infile, "r");
    if (!file) {
        Reporterror(Error::Filenotfound, std::string(infile));
    }
    yyin = file;
    Filepreread(infile);

    if (!outfile) Reporterror(Error::Nooutputfile);

    file = fopen(outfile, "w");
    if (!file) {
        Reporterror(Error::Filenotfound, std::string(outfile));
    }
    yyout = file;
    std::ofstream fout(outfile);
    std::streambuf *oldbuf = std::cout.rdbuf(fout.rdbuf());

    ASTptr root;
    yyparse(&root);
    if (!mainptr)
        Reporterror(Error::Nomain);
    NumErrorMessage();

    TreatMain(root);
    TraverseAST(root);
    SSAOptim();
    RemoveRedundantBaseBlock();

    if (mode == WorkingMode::EEMODE)
        DumpEE2file();
    else {
        TranslateEE2TG();
        EliminateSTLDTG();
        if (mode == WorkingMode::TGMODE)
            DumpTG2file();
        else
            DumpRV2file();
    }

    std::cout.rdbuf(oldbuf);
    fout.close();
}

static inline void PrintHelpInfo(const char *p) {
    std::cerr << "usage: " << p << " -S [-e <INPUT> | -t <INPUT>] -o <OUTPUT>" << std::endl;
}