### 解题思路
gcd算法（其实就是辗转相除法）:
int gcd(int a,int b)    { return !b? a:gcd(b,a%b); }

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 == str2 + str1)  ?  str1.substr(0, gcd(str1.size(), str2.size()))  : "";
    }
};
```