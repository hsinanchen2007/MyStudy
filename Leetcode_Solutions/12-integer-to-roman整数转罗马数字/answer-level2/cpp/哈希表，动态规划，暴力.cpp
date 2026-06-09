### 解题思路
总感觉做过这道题，  写了第一个解，太垃圾了。看了解答里的动态规划觉得挺好的，让自身减去匹配上的值，运行结果也很垃圾。
没想到最快的是暴力法。。。把所有可能列出来。。

### 代码

```cpp
// #include <math.h>

class Solution {
public:
    // 执行用时 :56 ms, 在所有 C++ 提交中击败了5.18% 的用户
    // 内存消耗 :11.5 MB, 在所有 C++ 提交中击败了22.61%的用户
    string intToRoman(int num) {
        unordered_map<int, string> harsh = {{1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},{40,"XL"},{50,"L"},{90,"XC"},{100,"C"},{400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}};
        int digit = -1;
        string res;
        int number = num;
        while(number!=0){
            ++digit;
            number/=10;
        }
        while(digit>=0){
            int temp = num/int(pow(10,digit));
            if(temp !=0){
                if(temp==1||temp==4||temp==5||temp==9){
                    res+=harsh[temp*int(pow(10,digit))];
                }
                else if(temp<4&&temp>1){
                    for(int i=0;i<temp;++i){
                        res += harsh[int(pow(10,digit))];
                    }
                }
                else{
                    res += harsh[5*int(pow(10,digit))];
                    for(int i = 5;i<temp;++i){
                        res += harsh[int(pow(10,digit))];
                    }
                }
            }
            num = num%int(pow(10,digit));
            --digit;
        }
        return res;
    }


    // 执行用时 :44 ms, 在所有 C++ 提交中击败了5.18% 的用户
    // 内存消耗 :8.9 MB, 在所有 C++ 提交中击败了45.93%的用户
    string intToRoman(int num) {
        vector<int> number = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> s = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res;
        for(int i=0;i<number.size();++i){
            while(num>=number[i]){
                res+=s[i];
                num-=number[i];
            }
        }
        return res;
    }


    string intToRoman(int num) {
        char* c[4][10] = {
            {"","I","II","III","IV","V","VI","VII","VIII","IX"},
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"","M","MM","MMM"}
        };
        string roman;
        roman.append(c[3][num / 1000]);
        roman.append(c[2][num / 100 % 10]);
        roman.append(c[1][num / 10 % 10]);
        roman.append(c[0][num % 10]);
         
        return roman;
    }
    // 执行用时 :8 ms, 在所有 C++ 提交中击败了86.66% 的用户
    // 内存消耗 :6.1 MB, 在所有 C++ 提交中击败了100.00%的用户
};
```