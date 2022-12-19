执行用时 :
20 ms, 在所有 Python 提交中击败了55.80%的用户
内存消耗 :
11.7 MB, 在所有 Python 提交中击败了70.98%的用户

### 代码

```python
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0: return 0
        if n == 1: return 1
        if n == 2: return 2
        s = [0] * (n+1)
        s[0], s[1], s[2] = 0, 1, 2
        for i in range(3, n+1):
            s[i] = s[i-1] + s[i-2]
            # print(i, end = ',')
        return s[-1]
```