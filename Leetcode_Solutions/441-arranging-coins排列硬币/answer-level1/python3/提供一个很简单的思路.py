### 解题思路
用整数n减去第i列的值，直到减完的值少于第i列的值，就返回i-1的值，即前i-1列是完整的，也可用等差数列的公式直接计算。

### 代码

```python3
class Solution:
    def arrangeCoins(self, n):
        if n<=1:
            return n
        for i in range(n+1):
            if n>=i:
                n=n-i
            else:
                return i-1

```