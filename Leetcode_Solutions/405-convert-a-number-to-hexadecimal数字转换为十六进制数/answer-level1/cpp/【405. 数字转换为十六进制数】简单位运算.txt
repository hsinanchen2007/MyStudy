### 思路一：位运算
每次取num的二进制表示的右边四位，然后将其转为十六进制，接着再将数右移四位，直到num为0。

### 代码

```cpp
class Solution {
public:
    string toHex(int num) {
        string res;
        for (int i = 0; num && i < 8; ++i) {
            int t = num & 0xf;
            if (t >= 10) res = char('a' + t - 10) + res;
            else res = char('0' + t) + res;
            num >>= 4;
        }
        return res.empty() ? "0" : res;
    }
};
```

### 另一种写法
```c++
class Solution {
public:
    string toHex(int num) {
        string res, str("0123456789abcdef");
        for (int i = 0; num && i < 8; ++i) {
            res = str[num & 0xf] + res;
            num >>= 4;
        }
        return res.empty() ? "0" : res;
    }
};
```
