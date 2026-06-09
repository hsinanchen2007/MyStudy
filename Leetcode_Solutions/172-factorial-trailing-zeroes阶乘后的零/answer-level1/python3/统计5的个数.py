### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def trailingZeroes(self, n: int) -> int:
        # 尾部的 0 由 2 * 5 得来，2 的数量明显多于 5 的数量，因此只要统计有多少个 5 即可。
        # 对于一个数 N，它所包含 5 的个数为：N/5 + N/52 + N/53 + ...，
        # 其中 N/5 表示不大于 N 的数中 5 的倍数贡献一个 5，N/52 表示不大于 N 的数中 52 
        # 的倍数再贡献一个 5 ...。
        
        # 递归法
        # return 0 if n == 0 else n // 5 + self.trailingZeroes(n // 5)

        # 迭代法
        count = 0
        while n > 0:
            n = n // 5
            count += n
        return count
```