### 解题思路
二分法寻找最小的数，left、right分别为左右指针，while循环将left与right更新为含有逆序的部分，当right-left<=2返回最小值

### 代码

```python3
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left,right=0,len(nums)-1
        res=0
        while left<=right:
            mid=(left+right)//2
            if right-left<=2:
                res=min(nums[left:right+1])
                break
            if nums[left]<nums[mid]<nums[right]:
                right=mid
            elif nums[left]<nums[mid]:
                left=mid
            elif nums[mid]<nums[right]:
                right=mid
            
        return res

```