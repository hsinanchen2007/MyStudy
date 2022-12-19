指针i，j。i指向:num[i]=val， j用于遍历。
如果num[j]!=val,则num[i]=num[j],i++


```
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        for j in range(len(nums)):
            if nums[j]!=val:
                nums[i]=nums[j]
                i+=1
        return i
```
