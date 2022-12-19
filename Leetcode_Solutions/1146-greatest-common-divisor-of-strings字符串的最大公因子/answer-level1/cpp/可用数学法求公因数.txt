### 解题思路

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0,mygcd((int)str1.length(),(int)str2.length()));
    }
    int mygcd(int a,int b){
        while(b^=a^=b^=a%=b);
        return a;
    }
};
```