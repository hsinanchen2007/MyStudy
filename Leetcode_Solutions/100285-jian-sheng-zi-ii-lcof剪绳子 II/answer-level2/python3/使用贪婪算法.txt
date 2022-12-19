### 解题思路
执行用时 :32 ms, 在所有 Python3 提交中击败了91.16% 的用户
内存消耗 :13.3 MB, 在所有 Python3 提交中击败了100.00%的用户

### 代码

```python3
class Solution:
    def cuttingRope(self, n: int) -> int:
        # 应用贪婪算法
        if n < 2:return 0
        if n == 2:return 1
        if n == 3:return 2
        t = n//3
        if n%3 == 1: t-=1
        s = (n-3*t)/2
        res = int(3**t)*int(2**s)
        return res%int(1e9+7)
```