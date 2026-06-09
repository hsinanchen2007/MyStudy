### 解题思路
一旦发现，第i个元素比i-1个小，那么第i-1个元素换成后面元素中比它大的最小元素，后面的升序排列
时间复杂度不错，基本在O(mn)左右，但是空间复杂度不好，也勉强算是常数空间，但是逼近O(n)了

### 代码

```python3
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums)-1, 0, -1):
            if nums[i] > nums[i-1]:  
                subNums = sorted(nums[i:len(nums)])
                for j in subNums:
                    if j>nums[i-1]:
                        newSub=j
                        break
                k = nums.index(newSub,i)
                nums[i-1],nums[k] = nums[k],nums[i-1]
                nums[i:] = sorted(nums[i:])
                return nums    
        return nums.sort()
```