### 解题思路
如果第一大的数大于２×第二大的数，返回Ｔｒｕｅ

### 代码

```python3
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        max_first = max_second = float("-inf")
        max_index = -1
        for i,n in enumerate(nums):
            if n > max_second and n < max_first:
                max_second = n
            elif n > max_first:
                max_first, max_second = n, max_first
            
            if n >= max_first:
                max_index = i

        return max_index if max_first >= 2 * max_second else -1

        
```