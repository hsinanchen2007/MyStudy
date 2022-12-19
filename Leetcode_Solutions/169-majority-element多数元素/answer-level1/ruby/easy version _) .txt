### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        temp, count = 0, 0 
        for i in range(len(nums)):
            if count == 0:
                temp = nums[i]
                count = count + 1
            else:
                if temp == nums[i]:
                    count = count + 1
                else:
                    count = count - 1
        return temp 
```