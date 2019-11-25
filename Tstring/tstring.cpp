#include <iostream>
#include <stdexcpt.h>
#include "tstring.h"

using namespace std;

TString::TString(const char* s){
    if(s != nullptr){
        len = strlen(s);
        ptr = new char[len + 1];
        strcpy(ptr,s);
    }
    #ifdef DEBUG
        cout<<"TString c-tor "<<len<<" - "<< (ptr ? ptr : "pusty ") <<'\n';
    #endif
}

TString::~TString(){
    #ifdef DEBUG
        cout<<"TString d-tor "<<len<<" - "<< (ptr ? ptr : "pusty ") <<'\n';
    #endif
    delete [] ptr;    
}

TString::TString(const TString& s) : len(s.len){
    if(len > 0){
        ptr = new char[len+1];
        strcpy(ptr,s.ptr);
    }
    #ifdef DEBUG
        cout<<"TString cc-tor "<<len<<" - "<<(ptr?ptr:"pusty")<<"\n";
    #endif
}

TString& TString::operator=(const TString& s){
    if(this != &s){
        delete [] ptr;
        ptr = nullptr;
        len = s.len;
    }
    if(len>0){
        ptr = new char[len+1];
        strcpy(ptr,s.ptr);
    }
    #ifdef DEBUG
        cout<<"TString copy operator "<<len<<" - "<<(ptr?ptr:"pusty")<<"\n";
    #endif
    return *this;
}

TString::TString(TString&& s) : ptr(s.ptr), len(s.len){
    s.ptr = nullptr;
    s.len = 0;
    #ifdef DEBUG
        cout<<"TString mvc operator "<<len<<" - "<<(ptr?ptr:"pusty")<<"\n";
    #endif
}

TString& TString::operator=(TString&& s){
    delete [] ptr; //kasowanie starego zasobu obiektu po lewej stronie
    ptr = s.ptr;
    len = s.len;
    s.ptr = nullptr;
    s.len = 0;
    #ifdef DEBUG
        cout<<"TString move operator "<<len<<" - "<<(ptr?ptr:"pusty")<<"\n";
    #endif
    return *this;
}
//len dlugosc obiektu
char& TString::operator[](size_t n){
    if(!ptr) throw "pusty obiekt - lancuch znakowy jako obiekt wyjatku";
    if(n < len) throw ptr[n];
    throw out_of_range("W klasie TString argument spoza zakresu");
}

const char& TString::operator[](size_t n) const{
    if(!ptr) throw "pusty obiekt - lancuch znakowy jako obiekt wyjatku";
    if(n < len) throw ptr[n];
    throw out_of_range("W klasie TString argument spoza zakresu");
}

char *TString::insert(size_t pos, const char *c){
    if(pos <= len){
        size_t oldlen = len;
        len = len + strlen(c);
        char *tmp = new char[len + 1];
        strcpy(tmp, ptr);

        for (size_t i = pos; i < pos + strlen(c);++i){
            tmp[i] = c[i-pos];
        }

        for (size_t i = pos; i < oldlen;++i){
            tmp[i + strlen(c)] = ptr[i];
        }
        delete[] ptr;
        ptr = tmp;
        return ptr + pos;
    }
    else
    {
        throw out_of_range("zly argument");
    }
    return ptr;
}