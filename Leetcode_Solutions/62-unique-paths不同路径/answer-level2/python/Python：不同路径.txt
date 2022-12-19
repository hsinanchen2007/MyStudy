### 解题思路
纯数学：排列组合
标准组合公式：C(n-1,m+n-2)

### 代码

```python3
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        a=b=1
        for i in range(1,n):
            a=a*i
        for i in range(m,m+n-1):
            b=b*i
        return b//a
```