### 解题思路
排序后输出数组中间的数,人生苦短,我用python
Σ( ° △ °|||)︴

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        return (nums[len(nums)//2])
```