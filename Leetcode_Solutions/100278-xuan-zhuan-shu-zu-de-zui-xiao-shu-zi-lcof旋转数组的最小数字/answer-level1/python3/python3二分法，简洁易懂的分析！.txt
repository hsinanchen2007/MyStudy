解题思路：  
```coffeescript
时间复杂度最小，就得二分法。  
二分法的本质是去掉无用区间保留有用区间，  
对本题来说，就是在左/中/右3个数之间的2个区间中，  
去掉单调区间（包括全等和严格、非严格的递增两种），  
保留非单调区间（区间内有大变小的情况）。
```
解题代码：
```python
## 二分法通用模版
class Solution:
    def minArray(self, nums: List[int]) -> int:
        l,r=0,len(nums)-1
        while l+1<r:
            m=(l+r)//2
            if nums[m]<nums[r] or len(set(nums[m:r+1]))==1:
                r=m
            elif nums[m]>nums[r] or len(set(nums[l:m+1]))==1:
                l=m+1
        return min(nums[l],nums[r])
```
效率分析：  
```less
执行用时 :36 ms, 在所有 Python3 提交中击败了97.77%的用户  
内存消耗 :13.6 MB, 在所有 Python3 提交中击败了100.00%的用户  
时间复杂度一般是O(logN)，最坏是O(N)  
```

