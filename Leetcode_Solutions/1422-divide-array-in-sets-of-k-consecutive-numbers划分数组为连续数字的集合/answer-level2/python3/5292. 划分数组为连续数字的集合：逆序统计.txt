### 解题思路

统计，验证。

### 代码

```python []
class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        d = collections.Counter(sorted(nums, reverse=True))
        while d:
            s, n = d.popitem()
            for i in range(s + 1, s + k):
                if d[i] < n:
                    return False
                elif d[i] == n:
                    del d[i]
                else:
                    d[i] -= n
        return True
```
```python []
class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        d = collections.defaultdict(int)
        for i in sorted(nums, reverse=True):
            d[i] += 1
        while d:
            s, n = d.popitem()
            for i in range(s + 1, s + k):
                if d[i] < n:
                    return False
                elif d[i] == n:
                    del d[i]
                else:
                    d[i] -= n
        return True
```

![image.png](https://pic.leetcode-cn.com/b29a70f417343a897398463295a01327790058de0479036f4a440d5069ef8c88-image.png)

