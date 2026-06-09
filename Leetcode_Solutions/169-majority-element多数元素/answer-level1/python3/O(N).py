### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        times = {}
        for i in nums:
            if i not in times:
                times[i] = nums.count(i)
                if times[i] > len(nums)//2:
                    return i
        print('null')
        return 0
```