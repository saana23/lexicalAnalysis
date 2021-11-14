#include<bits/stdc++.h>
#include <regex>
using namespace std;

#define all(a)                      (a).begin(),(a).end()

vector<string> keywrd = {"auto","double","int","struct","break","else","long","switch","case","enum","register",
"typedef","char","extern","return","union","const","short","float","unsigned","continue","for","signed","void","default",
"goto","sizeof","volatile","do","if","static","while","BEGIN","END","PRINT","INTEGER","REAL","STRING","FOR"};
vector<string> punctuation = {" ","+","-","*","/",",",";",">","<","=","(",")","[","]","{","}","&","|"};
vector<string> operators = {"+","-","*","/",">","<","=","|","&",":="};

bool handlenumbers(std::string const& input) {
    static const std::regex doubleRegex{ R"([+\-]?(?:0|[1-9]\d*)(?:\.\d*)?(?:[eE][+\-]?\d+)?)" };
    static const std::regex intRegex{ R"(\d+)"};

    if (std::regex_match(input, intRegex)){
        istringstream inputStream(input);
        int i;
        inputStream >> i;
        cout << input << " is a INTEGER\n";
        return true;
    } else if (std::regex_match(input, doubleRegex)) {
        istringstream inputStream(input);
        double d;
        inputStream >> d;
        cout << input << " is a FLOATING POINT\n";
        return true;
    }
    return false;
}





void solve(string s){
    if(find(all(operators), s) != operators.end()){
        cout << s << " is a Operator\n";
    }

    else if(find(all(keywrd), s) != keywrd.end()){
        cout << s << " is a Keyword\n";
    }
    else if(handlenumbers(s)==0){
        cout << s << " is an indentifier\n";
    }
}

int main(){
    string s;
    string str_occ = "";
    bool flag = false;

    // reading file input:
    freopen("inputfile.txt", "r", stdin);

    while(cin >> s){
        if(s[0]=='"' || flag){
            str_occ=str_occ+" "+s+" ";
            flag = true;
            if(s.back()=='"') {
                cout<<str_occ<<" is a String\n";
                str_occ = " ";
                flag = false;
            }
        } else solve(s);
    }
}
