### 解题思路
先选定第一个值，根据target算出第二个值，如果该值在列表内且跟第一个值不是同一个，则返回其索引。

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i,v in enumerate(nums):
            try:
                j=nums[i+1:].index(target-v)
            except:
                continue
            return [i,j+i+1]
```