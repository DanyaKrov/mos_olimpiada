#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long long itc_len(string str){
    long long len = 0;
    while (str[len] != '\n')
        len++;
    return len;
}
long long ToInt(string str){
    long long num = 0;
    for(int i = 0; i < itc_len(str); i++){
        if (str[i] >= '0' && str[i] <= '9'){
            num = num * 10 + (str[i] - '0');
        }
    }
    return num;
}
int itc_len_num(long long number)
{
    if (number < 0)
        number *= -1;
    int kol_10 = 0;
    while (number >= 10){
        kol_10 ++;
        number /= 10;
    }
    return kol_10 + 1;
}
int main()
{
    vector<int> values(10)/*= { 4, 5, 2, 3, 3, 1, 4, 4, 1, 6 }*/;
    values[0] = 4;
    values[1] = 5;
    values[2] = 2;
    values[3] = 3;
    values[4] = 3;
    values[5] = 1;
    values[6] = 4;
    values[7] = 4;
    values[8] = 1;
    values[9] = 6;
    int num;
    long long ans;
    ifstream myfile("a1.txt");
    int count = 1;
    myfile >> count;
    for (int i = 0; i < count; i++){
        ans = 0;
        myfile >> num;
        for (int i =0; i < num; i++)
            ans += values[i % 10];
        for (int i = 0; i < itc_len_num(num); i++)
            ans += 2 * i;
        cout <<ans <<'\n';
    }
    myfile.close();
    return 0;
}
