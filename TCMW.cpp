#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
void makeDirs();
void makeInputs(int,int,int,int);
void makeAnInput(int,int,int,int);
void makeOutputs(int);
void copyCode();
void clear();
int main(){
    int n=10,m=1,a=1,b=10;
    srand(time(NULL));
    cout << "number of test cases: ";
    cin >> n;
    cout << "number of each test input numbers: ";
    cin >> m;
    cout << "from? ";
    cin >> a;
    cout << "to? ";
    cin >> b;
    makeDirs();
    makeInputs(n,m,a,b);
    copyCode();
    makeOutputs(n);
    /**/cout << "making outputs compeleted\n";
    clear();    
    cout << "\n*** Done =) ***";
}
void makeDirs(){
    system("rmdir /S /Q problem");
    /**/cout << "problem dir deleted\n";
    system("mkdir problem && cd problem && mkdir in && mkdir out");
    /**/cout << "problem in and out dirs making compeleted\n";
}
void makeInputs(int n, int m, int a, int b){
    for(int i=0 ; i<n ; i++){
        makeAnInput(i,m,a,b);
    }
}
void makeAnInput(int i, int m, int a, int b){
    ofstream  file;
    file.open(".\\problem\\in\\input"+to_string(i+1)+".txt");
    for (int j=0 ; j<m ; j++){
        file << rand()%(b-a+1)+a;
        file << '\n';
    }
    file.close();
}
void makeOutputs(int n){
    for(int i=0 ; i<n ; i++){
        string s="cd .\\problem\\out && code.exe <..\\in\\input"+to_string(i+1)+".txt > output"+to_string(i+1)+".txt";
        const char *c= &s[0];
        system(c);
    }
}
void copyCode(){
    system("g++ code.cpp -o code.exe && copy code.exe .\\problem\\out");
}
void clear(){
    system("cd .\\problem\\out && del -f code.exe");
}
