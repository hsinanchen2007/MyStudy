![image.png](https://pic.leetcode-cn.com/db5f49cb8ab580ad88d52131bd3c0c452d128e234eb42bdfdfbedaa4fd7a3dbd-image.png)

解题思路，先利用普通二分法判断nums中是否包含target
1. 如果不包含，结束循环时return [-1, -1];
2. 如果包含，则从包含点mid开始, midleft = midright = mid，将区间分为[left, midleft]和[midright, right]，分别寻找两个区间中最靠左的target index和最靠右的targe index
3. 左区间找 leftmid = (left + midleft) // 2,判断leftmid位置及其左边的值来决定区间是向左二分还是向右二分，如果leftmid-1位置的值 == target, 说明左区间的左区间依旧包含target,则左区间向左二分，否则向右二分。同理判断右区间。

```python []
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums: return [-1, -1]
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target: # if contains target
                midleft = midright = mid
                while nums[left] != target or nums[right] != target:
                    leftmid = (left + midleft) // 2
                    if nums[leftmid] == target:
                        if nums[leftmid - 1] == target: # if left interval is not that left
                            midleft = leftmid
                        else:
                            left = leftmid # if left interval is too left
                    elif nums[leftmid] < target:
                        left = leftmid + 1
                    else:
                        midleft = leftmid - 1
                
                    rightmid = (right + midright) // 2
                    if nums[rightmid] == target:
                        if nums[rightmid + 1] == target: # if right interval is not that right
                            midright = rightmid
                        else:
                            right = rightmid # if right interval is too right
                    elif nums[rightmid] < target:
                        midright = rightmid + 1
                    else:
                        right = rightmid - 1
                return [left, right]
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return [-1, -1] # if not contains target
```
