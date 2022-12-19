### 解题思路
看了很多大佬们的代码，感觉思路都一样，在nums[mid]==nums[left]的时候采取的都是left+=1继续验证。
我的则是把列表分为左右两半，分别二分。

### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        n=len(nums)-1
        return self.__find_t(nums,0,n,target)

    def __find_t(self,nums,left,right,target):
        while left<=right:
            mid=(left+right)//2
            if left==right:return nums[left]==target
            if nums[mid]==target:return True
            elif nums[left]==nums[mid]:
                if self.__find_t(nums,left,mid-1,target):return True
                if self.__find_t(nums,mid+1,right,target):return True
                return False
            elif nums[left]<nums[mid]:
                if nums[mid]<target:
                    left=mid+1
                else:
                    if nums[left]==target:return True
                    elif nums[left]<target:
                        right=mid-1
                    else:left=mid+1
            else:
                if nums[mid]>target:
                    right=mid-1
                else:
                    if nums[left]==target:return True
                    elif nums[left]<target:
                        right=mid-1
                    else:
                        left=mid+1
        return False
```