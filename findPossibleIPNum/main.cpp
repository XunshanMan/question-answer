#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;
bool judgeNum(string& in);

int main(){
    //FILE* id = freopen("/home/lzw/in.txt","r",stdin);
    string inString;

    cin >> inString;


    // --------------------

    int strsize = inString.size();

//    if (strsize == 4){
//        cout << 1 << endl;
//        return 0;
//    }

    //test
    //cout << "size:" << strsize << endl;

    // 10001
    // 分别取数

    int ipNum = 0;

    for(int i=1 ; i <= strsize-3; i++){
        // i 第一段的个数
        string str1 = inString.substr(0, i);
        if (!judgeNum(str1)) continue;

        for (int p=1; p<=strsize - i - 2; p++){
            string str2 = inString.substr(i, p);
            if (!judgeNum(str2)) continue;

            for (int q=1; q<=strsize - i - p - 1; q++){
                string str3 = inString.substr(i+p, q);
                if (!judgeNum(str3)) continue;

                string str4 = inString.substr(i+p+q);
                if (!judgeNum(str4)) continue;

                //cout << str1 << ',' << str2 << ',' << str3 <<',' << str4 << endl;
                ipNum ++;
            }
        }

    }

    cout << ipNum << endl;


    return 0;
}

bool judgeNum(string& in){
    int size= in.size();
    //cout << "judge Num, in:" << in << endl;
    if (size >1 && in[0] == '0'){
        // 两位以上的数，第一个数不能是0
        return false;
    }
    if (atoi(in.c_str()) > 255) return false;
//    for (int i=0;i<size-1;i++){
//        if(in[i] == '0' && in[i+1] == '0')
//            return false;
//    }
    return true;
}
