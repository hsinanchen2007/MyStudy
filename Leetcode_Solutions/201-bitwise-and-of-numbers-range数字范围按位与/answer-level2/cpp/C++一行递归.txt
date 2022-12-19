### 解题思路
如果$m=n$，结果显然为$m$。如果$m\neq n$，那么$[m,n]$区间中一定有奇有偶，所以结果的最低位一定为0。因此，我们就可以将$m$和$n$都右移一位（因为最后一位已经确定为0了），递归计算，再将得到的结果左移一位，就是我们需要的答案。

### 代码

```cpp
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        return m == n ? m : rangeBitwiseAnd(m >> 1, n >> 1) << 1;
    }
};
```