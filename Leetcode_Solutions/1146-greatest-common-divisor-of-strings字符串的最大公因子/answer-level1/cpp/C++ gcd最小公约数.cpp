### 解题思路
利用gcd求出最小公倍数，根据总长度与最小公倍数的商 判断截断的字符串是否为最长子串

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
       if(str1+str2!=str2+str1){
           return "";
       }
       int len1=str1.size();
       int len2=str2.size();
       string str=str1.substr(0,__gcd(len1,len2));
       if(judge(str,str1)&&judge(str,str2)){
           return str;
       }
       return "";
    }

    bool judge(string small,string big){
       int len=big.size()/small.size();
       string tmp;
       for(int i=1;i<=len;i++){
           tmp+=small;
       }
       return tmp==big;
    }
};
```