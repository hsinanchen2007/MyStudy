#思路分析：二分法
#这一题的思路就是用二分法找乱序部分的左端点
#如果mid是有序的则在mid的右侧搜索
#如果mid是乱序的则在mid的左侧搜索
#最终肯定会收敛到一个元素（left），如果乱序在所给序列内，收敛的left即为所求
#但是如果所给序列完全有序如（0,1,2,3），那么left的下一个即为所求。即需要对收敛结果进行讨论
```

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        left = 0
        right = len(nums)-1
        while(left<right):
            mid = (left+right)//2
            if nums[mid]==mid:
                left = mid+1
            else:
                right = mid-1
        if nums[left]==left:
            return left+1
        else:
            return left
```
