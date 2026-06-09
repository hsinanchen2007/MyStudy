```cpp
class Solution {
public:
    int reverse(int x) {
        string s, m = x > 0 ? "2147483647" : "-2147483648";
        for(s = x >= 0 ? "" : "-"; x; x/=10) s += to_string(abs(x % 10));
        return s.size() == m.size() and s > m or s == "" ? 0 : stoi(s);
    }
};
```
- 先把数字反转并转为字符串`s`
- 字符串的比较结果 等价于 等长正整数的比较结果，我们可以利用这一点直接判断溢出