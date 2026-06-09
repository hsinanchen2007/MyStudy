## 分析：

- 首先这道题说了不能使用if-else和比较运算符。
- 也就是说库函数调用到这两个的也不能用，想max，sort都不能用。然后还有三目运算符更加不能用。
- 这题怎么做，其实题目的四个提示已经告诉你了。(你们可以自行去看。)
- 问题其实还剩两个，一个是怎么取出int类型的符号位，另一个是超过int类型怎么办。
- 后者可以用long来解决，那么前者呢？
- 这里需要了解一下long或者是int类型了。符号位都是在第一位上的，也就是说long类型右移63位就可以拿到。
- 其中有一点，正数右移高位补0，但是负数右移高位补1。
- 这里我放上一个链接，介绍了左移和右移在正数与负数中的情况。
- > https://www.csdn.net/gather_2b/MtzaIg4sOTctYmxvZwO0O0OO0O0O.html

## 代码：

```cpp
class Solution {
public:
    int maximum(int a, int b) {
        long k = (((long)a - (long)b) >> 63) & 1;
        return b * k + a * (k ^ 1);
    }
};
```
