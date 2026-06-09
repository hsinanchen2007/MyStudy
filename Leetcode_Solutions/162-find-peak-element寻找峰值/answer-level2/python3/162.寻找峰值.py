### 解题思路
实话实说我的复杂度是O(n)，不是O(logN) 
![image.png](https://pic.leetcode-cn.com/93de3922f75dbe9ab257150f077883b2ac9b155c08a7bdcc6e559458418df228-image.png)
我去看看复杂度的计算了。。
### 代码

```python3
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:

        max_index = nums.index(max(nums))
        nums_last_index = len(nums) - 1

        if len(nums)<=3:
            return max_index

        if max_index == 0 :
            return 0
        
        if max_index == nums_last_index:
            return nums_last_index

        for i in range(1,len(nums)-1):
            if nums[i-1]<nums[i] and nums[i+1]<nums[i]:
                return i
```