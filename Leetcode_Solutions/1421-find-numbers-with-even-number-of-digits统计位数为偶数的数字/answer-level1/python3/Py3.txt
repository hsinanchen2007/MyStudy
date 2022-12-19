![1.png](https://pic.leetcode-cn.com/4fac04c2e89fb76a9dc54f81d4fe64fd4cd7cee2549624ca6eac5ac37f410317-1.png)
```python
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        return len([i for i in map(len, map(str, nums)) if not i % 2])
```
