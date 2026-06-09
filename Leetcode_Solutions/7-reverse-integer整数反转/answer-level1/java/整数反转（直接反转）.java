#### 解题思路：

- **算法思路：** 为对当前数取对 $10$ 的余数，再一项项填入`res`尾部，即可完成 $int$ 翻转。
- **边界情况处理：** $int$ 取值范围为 $[-2^{31}, 2^{31} - 1]$ ，如果翻转数字溢出，则立即返回 $0$ 。
  - **Python：** 存储数字理论上是无限长度，因此每次计算完后判断`res`与`of`的大小关系即可；
  - **Java：** 数字计算会溢出，因此要判断`res`和`of / 10`的大小关系（即确定再添 $1$ 位是否会溢出）。
- **Python的坑：** 由于**Python**的 `//` 操作是向下取整，导致正负数取余 `%` 操作结果不一致，因此需要将原数字转为正数操作。

#### 代码：

```python []
class Solution:
    def reverse(self, x: int) -> int:
        y, res = abs(x), 0
        of = (1 << 31) - 1 if x > 0 else 1 << 31
        while y != 0:
            res = res * 10 + y % 10
            if res > of: return 0
            y //= 10
        return res if x > 0 else -res
```

```java []
class Solution {
    public int reverse(int x) {
        int res = 0;
        int of = ((1 << 31) - 1) / 10;
        while (x != 0) {
            if (Math.abs(res) > ((1 << 31) - 1) / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
}
```

