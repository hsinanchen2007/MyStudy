### 思路
* 首先是对整个数组进行一次遍历，所以时间复杂度是O(n).
* 在遍历的过程中，可以记录上一个元素为 temp，初始的时候记录 temp=nums[0].
* 在每次遍历的过程中，比较当前元素nums[i]与temp。
  * temp==nums[i],删除当前的nums[i]
  * temp!=nums[i],则将temp替换为nums[i],并且i=i+1.进行下一个元素的检查。
* 一直遍历到最后一个元素.
* 记得排除特殊用例，nums=[]的情况

```
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums)==0:
            return 0
        i=1
        temp=nums[0]
        while True:
            if i==len(nums):
                break
            if temp==nums[i]:
                del nums[i]
            else:
                temp=nums[i]
                i=i+1
        return i
```

### 改进
* 其实可以不用Temp这个变量，因为它本质上是比较当前元素和上一个元素，在比较的时候直接比较nums[i-1]和nums[n]即可。
```

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums)==0:
            return 0
        i=1
        while True:
            if i==len(nums):
                break
            if nums[i-1]==nums[i]:
                del nums[i]
            else:
                i=i+1
        return i
```
