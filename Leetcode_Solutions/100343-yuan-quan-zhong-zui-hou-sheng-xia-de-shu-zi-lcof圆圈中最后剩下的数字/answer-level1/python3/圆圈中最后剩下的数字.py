### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        # 递归法
        def helper(n, m):
            if n == 0:
                return 0
            x = helper(n - 1, m)
            return (m + x) % n

        return helper(n, m)

        # 迭代法，作者：LeetCode-Solution
        # remind = 0
        # for i in range(2, n+1):
        #     remind = (m + remind) % i
        # return remind

```