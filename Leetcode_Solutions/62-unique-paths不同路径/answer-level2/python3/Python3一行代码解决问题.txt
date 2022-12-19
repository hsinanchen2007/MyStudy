### 解题思路
数学问题，m x n的矩形，移动到右下方需要向左移动m-1次，向下移动n-1次，故总共可能路径为A(m+n-2, m+n-2) / (A(m-1, m-1) x A(n-1, n-1)),A代表全排列。
用c++的话可能会造成整数溢出，但可以通过优化解决。

### 代码

```python3
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        return int(math.factorial(m + n - 2) / (math.factorial(m-1) * math.factorial(n-1)))
```