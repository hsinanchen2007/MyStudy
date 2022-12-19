竖式计算, 同[第2题][两数相加 - 力扣（LeetCode）](https://leetcode-cn.com/problems/add-two-numbers/)

```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        int i = m - 1, j = n - 1, carry = 0;
        string ret = "";
        while (j >= 0 || i >= 0 || carry != 0) {
            if (i >= 0) carry += num1[i--] - '0';
            if (j >= 0) carry += num2[j--] - '0';
            ret += carry % 10 + '0';
            carry /= 10;
        }

        // 翻转字符串
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
```