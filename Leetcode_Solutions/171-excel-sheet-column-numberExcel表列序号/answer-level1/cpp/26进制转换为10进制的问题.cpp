### 解题思路
其实就是写一个26进制转换为10进制的问题，本来还考虑遇到特别大的数会出现问题，现在看来，应该不在考虑范围内。

### 代码

```cpp
class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        int len = (int)s.length();
        for (int i = 0; i < len; ++i) {
            int number = s.at(i) - 'A' + 1;
            int sqr = len - 1 - i;
            result = result + number * pow(26, sqr);
        }
        return result;
    }
};
```