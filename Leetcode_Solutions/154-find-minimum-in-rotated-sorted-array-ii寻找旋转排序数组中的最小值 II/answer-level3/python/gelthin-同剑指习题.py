### 解题思路
同剑指offer习题 [gethin-对部分样例二分](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/solution/gethin-dui-bu-fen-yang-li-er-fen-by-gelthin/)

注意要和 nums[0] 比，而不要和 nums[left] 比。

这里删去了二分中的加速代码，也对。



### 代码

```python3
class Solution:
    def findMin(self, nums: List[int]) -> int:
        # 同剑指 offer 习题，这里重做一遍
        n = len(nums)
        if n == 0:
            return
        if n == 1:
            return nums[0]
        if nums[0] < nums[-1]:
            return nums[0]
        elif nums[0] == nums[-1]:
            for i in range(1, n):
                if nums[i-1] > nums[i]:
                    return nums[i]
            return nums[0] # 若没找到，则说明全部相同
        else: ##到此，可以保证 nums[0]> nums[-1] 下面来进行二分 
            left, right = 0, n-1
            while left<right:
                mid = left + (right-left)//2
                if nums[mid] >= nums[0]:  # 这里有等于, 漏了等于会出错 
                    left = mid+1
                else:
                    right = mid
            
            return nums[left]


```