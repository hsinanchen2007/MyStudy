### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findLucky(self, arr: List[int]) -> int:
        ans = -1
        for i, j in collections.Counter(arr).items():
            if i == j:
                ans = max(ans, i)
        return ans
```