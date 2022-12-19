### 解题思路
看到复杂度要求是log n ，很显然是要用分治法查找。
主要思路：
1. 先确定目标值是否在数组中（用二分法，时间复杂度是log n）
2. 若找到了目标值的位置 ans，则将数组分为[0,ans]和[ans,n-1]两段，在两段中确定目标值的边界（仍用二分法，时间复杂度是 log n）
3. 对于[0,ans]，保证右边界始终是目标值；对于[ans,n-1]保证左边界始终是目标值
4. 整体复杂度仍是log n 
注意事项：
1. 要考虑到空数组等极端情况
2. 要小心二分法的右边界=左边界+1的情况，容易死循环
运算结果：
1. 时间：24ms，在所有 Python 提交中击败了98.03%的用户
2. 空间：12.3MB，在所有 Python 提交中击败了100.00%的用户
### 代码

```python
class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        left = 0
        right = len(nums)-1
        if (right < left or target < nums[left] or nums[right]<target ):
            return [-1,-1]
        if (right == left):
            if(nums[0]==target):
                ans = 0
            else:
                return[-1,-1]

        while(right > left):
            ans = int((right + left)/2)
            if nums[ans] > target:
                right = ans
            elif nums[ans] < target:
                left = ans     
                if (right == left + 1):
                    if(nums[right]==target):
                            return[right,right]
                    else:
                        return [-1,-1] 
            else:
                break
            
    
        left_1 =0
        right_1 = ans
        while(right_1 > left_1):
            ll = int((right_1 + left_1)/2)
            if(nums[ll]==target):
                right_1 = ll
            else:
                left_1 = ll
                if(right_1 == left_1 + 1):
                    break
        
        left_2 = ans
        right_2 = len(nums)-1
        while(right_2 > left_2):
            rr = int((right_2 + left_2)/2)
            if(nums[rr]==target):
                left_2 = rr
                if(right_2 == left_2 + 1):
                    if(nums[right_2]==target):
                        left_2 = right_2
                    break
            else:
                right_2 = rr

        return [right_1,left_2]
        
                


```