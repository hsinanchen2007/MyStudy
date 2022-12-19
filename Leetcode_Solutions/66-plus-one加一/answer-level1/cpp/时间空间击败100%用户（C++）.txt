## 解题思路
![image.png](https://pic.leetcode-cn.com/843ec6742463713a586b6ce7d9328f76d9fac8d1eefddd1255c1db75c09435b9-image.png)

设置一个$carry$变量表示是否有进位。类似于手工加法计算，设置一个$while$循环，从后往前扫描，循环条件为：1）$carry=1$即有进位；2）还没有扫描到第一个数。

若扫描到的数字$digits[i]$加一后进位，则其整除10结果为1，反之为0，结果作为$carry$新值；将$digits[i]$个位数，即模10的结果作为$digits[i]$新值。

最后，如果退出循环后，$carry$仍为1，代表还有一位进位，但是原向量的位数不够用了，所以在$digits$的头部插入1，作为补充的进位。

## 代码
```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size(), carry = 1;
        while(carry && i--) {
            carry = (digits[i] + 1) / 10;
            digits[i] = (digits[i] + 1) % 10;
        }
        if (carry) digits.insert(digits.begin(), 1);
        return digits;
    }
};
```