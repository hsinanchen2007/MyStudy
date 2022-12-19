### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        # if sum(ranges) == 0:
        #      return  -1
        ans, l, r, t = 0, 0, 0, 0
        while l < n:
            for i in range(t, n+1):
                if i - ranges[i] <= l and i + ranges[i] >= r:
                    new_t, r = i, i + ranges[i]
            if l == r:
                return -1
            t = new_t + 1
            ans += 1
            if r > n:
                break
            l = r
        return ans
```