在数组中，随机选择一个值pivot，将数组分成两个部分，less_part和great_part,然后再比较len(great_part)与k-1的大小，如果len(great_part)==k-1,则返回pivot为第K大的值，其余当len(great_part)大于或小于k-1,分别递归findKthLargest(great_part,k)和findKthLargest(less_part,k-len(great_part)-1)即可。

```
from random import randint
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        if k > len(nums):
            return
        index = randint(0,len(nums)-1)
        pivot = nums[index]
        less_part = [i for i in nums[:index]+nums[index+1:] if i < pivot]
        great_part = [i for i in nums[:index]+nums[index+1:] if i >= pivot]
        if len(great_part) == k-1:
            return pivot
        elif len(great_part) > k-1:
            return self.findKthLargest(great_part,k)
        else:
            return self.findKthLargest(less_part,k-len(great_part)-1)
```
