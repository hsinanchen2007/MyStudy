# 题解
本题的最优解法是双指针。对于二分法，有兴趣的可以自己去尝试。

## 双指针+滑动窗口

 1. 初试化左指针$l=0$。最小长度$res=Max$。初始化中间和$tmp=0$
 2. 遍历右指针，遍历区间$[0,n)$，对于$r$：
  	+ 记录累计和，$tmp+=nums[r]$。
  	+ 循环条件$tmp>=s$，进入循环：
  		* 记录此时的最小长度，$res=min(res,r-l+1)$
  		* 累计和减去左指针，并将左指针加一。$tmp-=nums[l],l+=1$，这两句的**顺序不能改变！**
 
 3. 若$res==Max$，返回0，否则返回$res$

### 复杂度分析
 - 时间复杂度：$O\left(n\right)$，进行了一次遍历。
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        n=len(nums)
        l=0
        res=float("inf")
        tmp=0
        for r in range(n):
            tmp+=nums[r]
            while(tmp>=s):
                res=min(res,r-l+1)
                tmp-=nums[l]
                l+=1
        return res if(res!=float("inf")) else 0
```
