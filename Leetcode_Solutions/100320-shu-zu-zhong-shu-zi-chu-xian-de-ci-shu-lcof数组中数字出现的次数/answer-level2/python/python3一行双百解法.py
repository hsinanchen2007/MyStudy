### 解题思路
collection.Counter

### 代码

```python3
class Solution:
    def singleNumbers(self, nums: List[int]) -> List[int]:
        return [x[0] for x in Counter(nums).items() if x[1] == 1]
```