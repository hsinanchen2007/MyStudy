### 解题思路

采用暴力方法，在超出时间限制与通过中摇摆

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        tem2 = len(nums)
        for i,item in enumerate(nums):
            
            tem3 = i+1
            while((tem3)<tem2 and (item+nums[tem3])!=target):
                tem3=tem3+1
            if((tem3)==tem2):
                continue
            else:
                return [i,tem3]




            

            

```