### 解题思路
在没有写代码之前，大概瞟了一眼别人用二分法的思路，于是手动写之，发现在很多边界的处理，比如是否+1，是否-1，用<=还是<都很难判断。
于是参考了一下Github上讲解二分法的文章，链接：https://github.com/labuladong/fucking-algorithm/blob/master/%E7%AE%97%E6%B3%95%E6%80%9D%E7%BB%B4%E7%B3%BB%E5%88%97/%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE%E8%AF%A6%E8%A7%A3.md

接下来的具体的思路：
首先明确要维护一个dp，第i个元素代表长度为i的子序列可能的最小数字。

当我们的新数字比第i个要大，比第i+1个要小，就可以更新第i+1个元素为新的数字。所以在二分的过程中，对于大于新数字的元素，可以不加理会；对于小于新数字的元素，记录它的index；对于等于新数字的元素，说明新的数字对dp没有作用，直接跳过。

所以经过二分法，得到了最大的比新数字小的数字位置。

这里还有一个trick，将关键位置loc变量的初始值等于-1，如果在整个的二分过程中loc没有被改变，说明新数字比所有的dp元素都要小，可以直接代替第0位的元素；同时，如果loc最后==len(dp)-1，说明新数字比所有元素都要大，就可以append上新的元素在dp上了

### 代码

```python3
import math
class Solution:
    def update(self, dp, new_num):
        if len(dp)==0:
            dp.append(new_num)
            return
        l, r = 0, len(dp)-1
        loc=-1
        while l<=r:
            
            mid = (l+r)//2
            if dp[mid]==new_num:
                return
            elif dp[mid]>new_num:
                r = mid-1
            elif dp[mid]<new_num:
                loc = mid
                l = mid+1
        if loc==len(dp)-1:
            dp.append(new_num)
        else:
            dp[loc+1] = new_num
        return

        

    def lengthOfLIS(self, nums: List[int]) -> int:
        if len(nums)==0:
            return 0
        dp = []

        
        for new_num in nums:
            self.update(dp, new_num)
        
        return len(dp)
```