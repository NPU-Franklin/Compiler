#pragma once
#ifndef SYSY_TOKEN_HPP_DR_
#define SYSY_TOKEN_HPP_DR_

class Token;

using TKptr = Token *;

#include "global.hpp"
#include "strtab.hpp"

class Token {
public:
    Token(int type_) : \
    lno(lineno), bgn(tokenpos - tokenwidth), end(tokenpos), type(type_) {};

    Token(int val_, int type_) : val(val_), \
    lno(lineno), bgn(tokenpos - tokenwidth), end(tokenpos), type(type_) {};

    Token(const char *p, int type_) : strptr(Inserttostrtab(p)), \
    lno(lineno), bgn(tokenpos - tokenwidth), end(tokenpos), type(type_) {};

    int val; // Reserved for INT_CONST
    STRptr strptr; // Reserved for IDENT
    int type; // Consistent with "parser.hpp" generated by yacc
    int lno, bgn, end; // Position information
};


#endif