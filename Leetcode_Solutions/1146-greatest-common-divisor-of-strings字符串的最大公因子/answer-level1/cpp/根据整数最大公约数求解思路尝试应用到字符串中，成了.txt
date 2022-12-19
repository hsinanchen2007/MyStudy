### 解题思路
https://www.runoob.com/cplusplus/cpp-examples-hcf-gcd.html
借鉴整数的最大公约数求解思想
### 代码

```cpp
#include<string>
class Solution {
public:
    //match用于判断作为减数的字符串是否是长字符串的子串
    bool match(string s1,string s2,int m){
        for(int i=0;i<m;i++){
            if (s1[i]!=s2[i])
                return false;
        }
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        while(str1.size()!=str2.size()){
            if(str1.size()>str2.size()&&match(str1,str2,str2.size())){
                str1=str1.substr(str2.size());
            }
            else{
                if(match(str2,str1,str1.size()))
                    str2=str2.substr(str1.size());
                else
                    return "";
            }
        }
        //结束while，这时str1只有等于str2才能得到最大公约数
        if(match(str1,str2,str2.size())){
            return str1;
        }
        return "";
    }
};
```