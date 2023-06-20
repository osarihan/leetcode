#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s);
};

int Solution::romanToInt(string s){
    int res = 0;
    int i = 0;
    int tempi = 0;
    int yeni = 0;

    while (s[i]){
        tempi = 0;
        yeni = 0;
        while (s[i] == 'I'){
            res += 1;
            yeni++;
            i++;
            cout << "I" << endl;
        }
        tempi = yeni;
        if (s[i] == 'V'){
            res += 5;
            while (tempi){
                res -= 2;
                tempi--;
                cout << "spinV" << "res" << res <<  endl;
            }
            cout << "V" << endl;
            tempi = 0;
            i++;
        }
        while (s[i] == 'X'){
            res += 10;
            if (tempi){
                while (tempi){
                    res -= 2;
                    tempi--;
                cout << "spinX" << "res" << res << endl;
                }
                tempi = 0;             
            }
            cout << "X" << endl;
            yeni++;
            i++;
        }
        tempi = yeni;
        if (s[i] == 'L'){
            res += 50;
            while (tempi){
                res -= 20;
                tempi--;
                cout << "spinL" << "res" << res << endl;
            }
            cout << "L" << endl;
            tempi = 0;
            i++;
        }
        while (s[i] == 'C'){
            res += 100;
            if (tempi){
                while (tempi){
                    res -= 20;
                    tempi--;
                }
                cout << "spinC" << "res" << res <<  endl;
                tempi = 0;                
            }
            cout << "C" << endl;
            yeni++;
            i++;
        }
        tempi = yeni;
        if (s[i] == 'D'){
            res += 500;
            while (tempi){
                cout << "spinD" << "res" << res <<  endl;
                res -= 200;
                tempi--;
            }
            cout << "D" << endl;
            tempi = 0;
            i++;
        }
        if (s[i] == 'M'){
            res += 1000;
            if (tempi){
                while (tempi){
                    cout << "spinM" << "res" << res <<  endl;
                    res -= 200;
                    tempi--;
                }
                tempi = 0;                
            }
            cout << "M" << endl;
            i++;
        }
    }
    return (res);
}

int main(){
    Solution a;

    cout << a.romanToInt("DCXXI");
}