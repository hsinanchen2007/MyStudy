### 解题思路
快慢指针从头开始扫描，快指针如果等于慢指针的值，跳过，如果不等于，慢指针的值置为快指针的值，快指针继续向右
### 代码


```
`python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        slow=fast=0
        while fast<len(nums):
            if nums[fast]!=nums[slow]:
                slow+=1
                nums[slow]=nums[fast]
            fast+=1
        return slow+1
```



