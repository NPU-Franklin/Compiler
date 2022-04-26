/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_CYGDRIVE_D_PROJECTS_COMPILER_SRC_PARSER_HPP_INCLUDED
# define YY_YY_CYGDRIVE_D_PROJECTS_COMPILER_SRC_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 3 "/cygdrive/d/Projects/Compiler/src/parser.y"

#include <memory>
#include <string>

#line 54 "/cygdrive/d/Projects/Compiler/src/parser.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
enum yytokentype {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    VOID = 259,                    /* VOID  */
    CONST = 260,                   /* CONST  */
    BREAK = 261,                   /* BREAK  */
    CONTINUE = 262,                /* CONTINUE  */
    IF = 263,                      /* IF  */
    ELSE = 264,                    /* ELSE  */
    RETURN = 265,                  /* RETURN  */
    WHILE = 266,                   /* WHILE  */
    ADD = 267,                     /* ADD  */
    SUB = 268,                     /* SUB  */
    MUL = 269,                     /* MUL  */
    DIV = 270,                     /* DIV  */
    MOD = 271,                     /* MOD  */
    ASSIGN = 272,                  /* ASSIGN  */
    EQ = 273,                      /* EQ  */
    NE = 274,                      /* NE  */
    LT = 275,                      /* LT  */
    GT = 276,                      /* GT  */
    LE = 277,                      /* LE  */
    GE = 278,                      /* GE  */
    NOT = 279,                     /* NOT  */
    AND = 280,                     /* AND  */
    OR = 281,                      /* OR  */
    LBRACK = 282,                  /* LBRACK  */
    RBRACK = 283,                  /* RBRACK  */
    LPAREN = 284,                  /* LPAREN  */
    RPAREN = 285,                  /* RPAREN  */
    LBRACE = 286,                  /* LBRACE  */
    RBRACE = 287,                  /* RBRACE  */
    COMMA = 288,                   /* COMMA  */
    SEMI = 289,                    /* SEMI  */
    DOT = 290,                     /* DOT  */
    REFER = 291,                   /* REFER  */
    IDENT = 292,                   /* IDENT  */
    INT_CONST = 293                /* INT_CONST  */
};
typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if !defined YYSTYPE && !defined YYSTYPE_IS_DECLARED
union YYSTYPE {
#line 25 "/cygdrive/d/Projects/Compiler/src/parser.y"

    std::string *str_val;
    int int_val;

#line 114 "/cygdrive/d/Projects/Compiler/src/parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse(std::unique_ptr<std::string> &ast);


#endif /* !YY_YY_CYGDRIVE_D_PROJECTS_COMPILER_SRC_PARSER_HPP_INCLUDED  */
