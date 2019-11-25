#include <iostream>
#include <string>
#include <fstream>
#include "tstring.h"

using namespace std;

TString fun(const char* s){
    return TString(s);
}

auto main() -> int{

    /*string s1, s2;
    cout << "wprowadz tekst: ";
    cin >> s1 >> s2;
    cout << "Wczytano: " << s1 << s2 << endl;
    getline(cin, s1, '@');
    cout << s1 << endl;
    ifstream plik("tekst.txt");
    if (plik) { cerr << "Brak pliku" << endl; exit(1); }
    s2. clear();
    while (!plik.eof() ){
        getline(plik, s1);
        s2 += s1 + "\n";
    }
    cout << s2 << endl;
    for (auto& c : s2 ) c = toupper(c);
    cout << s2 << endl;*/

    TString s1;
    TString s2("dzien dobry");
    TString s3= fun("obiekt w locie");    //move(s2);
    s1= fun("drugi obiekt w locie");    //move(s3);
    //cout<<s2[0]<<"\n";

    //for(auto c : s1) cout<<c<<"-";
    //for(size_t i=0; i<s1.size();++i) cout<<s1[i]<<"=";
    //cout<<"\n";

    cout<<s1<<"\n";
    cin >>s1;
    cout<<s1<<"\n";


    cout<<"-------------------------"<<"\n";

 }