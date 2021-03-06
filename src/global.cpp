#include "error.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::ifstream;
using std::stringstream;

vector<string> filecontent;

// Position Information
int lineno = 1, tokenpos = 1, tokenwidth = 0;

// Block #. 0 for the global scope
int blockno = 0;

// File Preread in (to facilitate error reporting)
void Filepreread(const string &str) {
    ifstream fin(str);
    if (fin.fail()) Reporterror(Error::Filenotfound, str);

    string tmp;
    while (getline(fin, tmp)) filecontent.push_back(tmp);

    if (filecontent.empty()) Reporterror(Error::Emptyfile, str);
}

// Array Dimension
vector<int> Arraydimprocess(const vector<int> &p) {
    if (!p.size()) return vector<int>(1, 1);
    vector<int> tmp(1, 1);

    int mul = 1;
    for (auto i = p.rbegin(); i != p.rend(); ++i) {
        mul *= *i;
        tmp.push_back(mul);
    }

    return tmp;
}

// From array index to a single number, do the convolution
int Arraylinearno(const std::vector<int> &arr, const std::vector<int> &ind) {
    int ret = 0;
    const int len = arr.size(), indlen = ind.size();

    // A Scalar
    if (len == 1) return 0;

    // An array
    for (int i = 0; i < indlen; ++i) {
        ret += (ind[i] * arr[len - 2 - i]);
    }
    return ret;
}

// Encode error message
string Encodemessage(const vector<int> &p) {
    int size = p.size();
    if (size == 1) return "int";
    string ret = "int ";

    // A ptr
    if (p.back() == 0) {
        ret += "[]";
        size -= 1;
    }

    stringstream sin;
    string tmp;
    for (int i = size - 1; i >= 1; --i) {
        sin << p[i] / p[i - 1];
        sin >> tmp;
        ret = ret + "[" + tmp + "]";
        sin.clear();
    }
    return ret;
}

// Encode error message
string Encodemessage(int p) {
    string ret;
    stringstream sin;
    sin << p;
    sin >> ret;
    return ret;
}