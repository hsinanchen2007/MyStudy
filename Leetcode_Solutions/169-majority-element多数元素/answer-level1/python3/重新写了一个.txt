### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 1
        curr = nums[0]

        for i in range(1,len(nums)):
            if count==0:
                curr = nums[i]
            if nums[i]==curr:
                count+=1
            else:
                count-=1
        if count:
            return curr
        return curr

```