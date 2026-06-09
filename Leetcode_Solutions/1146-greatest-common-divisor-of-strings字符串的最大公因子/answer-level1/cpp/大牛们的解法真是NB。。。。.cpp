### 解题思路


### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1) return "";
        return str1.substr(0,gcd(str1.length(),str2.length()));
    }
    int gcd(int a,int b){
        return b == 0 ? a : gcd(b,a % b);
    }
};
```