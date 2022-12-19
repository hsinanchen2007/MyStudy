### 解题思路
根据别人思路改的

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if ( str1 + str2 != str2 + str1 )
            return "";

        // 辗转相除法求 gcd
        return str1.substr(0, gcd( (int)str1.length(), (int)str2.length() ) );
    }
    int gcd(int a, int b ) {
        return b == 0 ? a : gcd( b, a % b );
    }
};
```