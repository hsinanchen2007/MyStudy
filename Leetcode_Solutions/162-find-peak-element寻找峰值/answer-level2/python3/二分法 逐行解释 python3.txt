# 题解
题目中有两个重要的条件：
 - $nums[i] ≠ nums[i+1]$
 - $nums[-1] = nums[n] = -∞$
若找到一个值，右侧的下个值更大，则在右侧一定存在峰值，反之，自身或者左侧一定存在峰值。
看到$O(log(n))$，想到二分法。

## 二分法
 1. 初试化左指针$l=0$，右指针$r=n-1$
 2. 循环条件$l<r$，进入循环：
 	* $mid=(l+r)//2$
 	* 若$nums[mid]>nums[mid+1]$，说明左侧的值更大，则$nums[mid]$或者左侧一定存在峰值。令$r=mid$，因为$mid$自身也可能是峰值。
 	* 否则，说明右侧的值更大，则右侧一定存在一个峰值。令$l=mid+1$.
 
 3. 返回$l$

### 复杂度分析
 - 时间复杂度：$O(log(n))$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        l=0
        r=len(nums)-1
        while(l<r):
            mid=(l+r)//2
            if(nums[mid]>nums[mid+1]):
                r=mid
            else:
                l=mid+1
        return l
```