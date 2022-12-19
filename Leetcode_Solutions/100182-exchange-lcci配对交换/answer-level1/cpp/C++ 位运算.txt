## 配对交换

> CC189 面试题 05.07
>
> 难度：
>
> - `简单`
>
> tags：
>
> - `位运算`

## 题目描述

配对交换。编写程序，交换某个整数的奇数位和偶数位，尽量使用较少的指令（也就是说，位0与位1交换，位2与位3交换，以此类推）。

**示例1:**

```
 输入：num = 2（或者0b10）
 输出 1 (或者 0b01)
```

**示例2:**

```
 输入：num = 3
 输出：3
```

**提示:** `num`的范围在[0, 2^30 - 1]之间，不会发生整数溢出。

------

## 思路

直接用位运算的方法求解：

```cpp
class Solution {
public:
  int exchangeBits(int num) {
    int even = num & 0xaaaaaaaa;
    int odd = num & 0x55555555;
    even = even >> 1;
    odd = odd << 1;
    int ans = even | odd;
    return ans;
  }
};
```

