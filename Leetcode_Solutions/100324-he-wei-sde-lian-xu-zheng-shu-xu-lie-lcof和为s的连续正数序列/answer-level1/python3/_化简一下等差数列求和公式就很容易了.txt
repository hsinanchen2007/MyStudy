### 解题思路
![Screen Shot 2020-03-06 at 02.04.58.png](https://pic.leetcode-cn.com/6e7c8ee2618d685fca5ab374c8d7c6cc06d63180452b7f2530f50eb1b6953b65-Screen%20Shot%202020-03-06%20at%2002.04.58.png)

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        ans = []
        t = 2*target
        for m in range(int(t**0.5), 1, -1):
            if t % m == 0:
                p = t//m + 1 - m
                if p % 2 == 0:
                    n = p//2
                    ans.append(list(range(n,n+m)))
        return ans
```