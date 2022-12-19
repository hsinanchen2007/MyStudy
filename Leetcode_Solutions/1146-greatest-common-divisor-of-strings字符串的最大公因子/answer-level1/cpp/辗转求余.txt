### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
//a>b 必须大数%小数 辗转相除法求最大公约数
   int _gcd(int a, int b) {
        while(b) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        return str1.substr(0, _gcd(str1.size(),str2.size()));
    }
};
```