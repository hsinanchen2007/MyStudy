### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        return str1+str2 != str2+str1 ? "":str1.substr(0,gcd(str1.size(),str2.size()));
    }
};
```