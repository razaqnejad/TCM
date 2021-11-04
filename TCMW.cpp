#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
void makeDirs();
void makeInputs(int,bool,int,int,int);
void makeAnInput(int,bool,int,int,int);
void makeOutputs(int);
void copyCode();
void clear();
int main(){
    bool type=0;
    int n=10,m=1,a=1;
    int b=10;
    srand(time(NULL));
    cout << "number of test cases: ";
    cin >> n;
    cout << "0. n depended \t 1. exact n? ";
    cin >> type;
    if(type){
        cout << "number of each test inputs: ";
        cin >> m;
    }else{
        cout << "Maximum of each test inputs: ";
        cin >> m;
    }
    cout << "from? ";
    cin >> a;
    cout << "to? ";
    cin >> b;
    makeDirs();
    makeInputs(n,type,m,a,b);
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
void makeInputs(int n, bool type, int m, int a, int b){
    for(int i=0 ; i<n ; i++){
            makeAnInput(i,type,m,a,b);

    }
}
void makeAnInput(int i, bool type, int m, int a, int b){
    int range= (type ? m : (rand()%m)+1);
    ofstream  file;
    file.open(".\\problem\\in\\input"+to_string(i+1)+".txt");
    if(!type){
        file << range << '\n';
    } 
    for (int j=0 ; j<range ; j++){
        if(!type){
            for(int h=0 ; h<3 ; h++){
                file << rand()%(b-a+1)+a;
                file << ' ';
            }
        }else{
            file << rand()%(b-a+1)+a;
        }
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
