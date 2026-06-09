这道题被因为越界和超时退回了好多次 hhh

通常的方法似乎都使用移位操作，也有不少用递归的。说实话我还是蛮佩服的。但是作为非科班学生，这种做法我感觉不太习惯。我就尝试用我更喜好的方式，浪费点内存，来实现类似于 log2 的功能，解决除法问题。

这道题我使用了取负值操作，否则可能需要很多 if 判断语句。

## 大体思路

对于样例 `[-80, -3]` 而言，首先我们开一个数组 `scr_div` (scratch divisor)，使得数组的第一个数为分母 `divisor = 3`，且后一个数恰好比前一个数大一倍。其对应一个 `scr_res` (scratch result) 数组，即 2 倍数等比数列：

```c++
scr_div = { -3,  -6, -12, -24, -48, -96 }
scr_res = {  1,   2 ,  4,   8,  16,  32 }
```

随后我们尝试

- 将 -80 减去 `scr_div` 的最末位数 -96，但这将大于零；
- 将 -80 减去 -48，得到 -32；而 `scr_div` 中的 -48 对应 `scr_res` 中的 16，因此结果 `result += 16`；
- 同理，-32 减去 -24 得到 -8；而 `scr_div` 中的 -24 对应 `scr_res` 中的 8，因此结果 `result += 8`；
- 但 -8 减去 -12 会大于零，因此跳过 -12 的情况；
- 以此类推，得到 `result = 16 = 8 + 2 = 26`。

上面的过程可以简单表示为
```
(-80) - (-48) => (-32) - (-24) => (-8) - (-6) => (-2) |
          16   +            8   +          2          = 26
```

如果我们实现知道除法的结果是 $n =$ `result`，那么该过程的时间和内存复杂度会是 $O(\log n)$；而 $n$ 不可能大于 $2^{32}$，因此一般来说还是很快的。程序的运行时间可以在 4ms 左右。

我想递归在最坏情况下，可能也需要用到这么大的内存空间；因为函数的堆栈也是占内存空间的。

## 陷阱：int 溢出

为了避免 int 溢出问题，我们首先讨论分母 `divisor` 为 1 或 -1 的情况；一方面是这个情况下的解是 trival 的，另一方面需要额外定义

```c++
-2147483648 / -1 = 2147483647
```

上述的大体思路的过程，几乎要求了分母 `divisor` 和分子 `dividend` 取固定的符号。我们程序中需要额外加两行重定义它们的符号。
但我们并不定义为正号，因为负数的值域比正数稍大一些。

## 代码实现

```c++
class Solution {
public:
    int divide(int dividend, int divisor) {
        // 0. 排除大部分极端情况
        //    但需要注意，下面没有排除极端情况 dividend = -2147483648 但 divisor != (+/-) 1
        if (divisor == 1) return dividend;
        else if (divisor == -1) return (dividend == -2147483648) ? 2147483647 : -dividend;
        // 1. 求取返回数值的符号
        bool sgn = (dividend > 0 == divisor > 0);
        // 2. 将分子与分母都取为负值 (避免出现 dividend = 2147483648)
        if (dividend > 0) dividend = -dividend;
        if (divisor > 0) divisor = -divisor;
        // 3. 开两个数组，其一保存 分母 * 2^n；其二保存 2^n
        //    如果希望避免 vector 重置大小，可以设 vector.reserve(33)，因为 log(2147483648, 2) = 33
        // 例子：80 / 3
        // scr_div = -3, -6, -12, -24, -48, -96 |  -96 > 81，数组停止增长
        // scr_res =  1,  2 ,  4,   8,  16,  32 |
        vector<int> scr_div{ divisor }, scr_res{ 1 };
        while (scr_div.back() > dividend && scr_div.back() > -1073741825) {
            scr_div.push_back(scr_div.back() + scr_div.back());
            scr_res.push_back(scr_res.back() + scr_res.back());
        }
        // 4. 从数组的末尾，尝试将分子减去 `scr_div` 中绝对值最大的数
        //    (-80) - (-48) => (-32) - (-24) => (-8) - (-6) => (-2) |
        //              16   +            8   +          2          = 26
        int result = 0;
        for (size_t i = scr_div.size(); i-- > 0; ) {
            if (dividend <= scr_div[i]) {
                dividend -= scr_div[i];
                result += scr_res[i];
            }
        }
        // 5. 将符号乘回来，得到最终结果。
        return sgn ? result : -result;
    }
};
```