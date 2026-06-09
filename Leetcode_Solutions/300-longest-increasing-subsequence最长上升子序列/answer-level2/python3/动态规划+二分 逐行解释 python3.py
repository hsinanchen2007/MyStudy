# 题解
## 动态规划
$dp[i]$表示到当前位置的最长上升子序列的长度。

 1. 特判，若数组为空，返回0
 2. 初试化$dp=[1,1,\cdots,1]$，长度为$n$，$dp[i]=1$表示每一位都可以为长度为1的最长上升子序列。
 3. 遍历$dp$，对于$i$，遍历区间$[1,n)$：
 	+ 遍历当前位置前的所有位置$j$，遍历区间$[0,i)$：
 		+ 若$nums[i]>nums[j]$，表示满足上升的条件。此时，更新当前位置的最长上升子序列的长度：$dp[i]=max(dp[i],dp[j]+1)$。
 
 4. 返回$dp$中的最大值。


	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
### 复杂度分析
 - 时间复杂度：$O(n^{2})$
 - 空间复杂度：$O(n)$

### Python
```python
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if(not nums):
            return 0
        n=len(nums)
        dp=[1]*n
        for i in range(n):
            for j in range(i):
                if(nums[i]>nums[j]):
                    dp[i]=max(dp[i],dp[j]+1)
        return max(dp)
```


## 动态规划+二分查找
定义$tail$数组，$tail[i]$保存遍历过程中长度为$i+1$的最长上升子序列的最小尾元素。
$tail$本身要求严格递增。
最终$tail$的长度就是整个数组最长上升子序列的长度。
解释：
这里长度等于最长上升子序列的长度，但是$tail$不一定为最长上升子序列。

 1. 特判，若数组长度小于$2$，返回数组长度。
 2. 初始化$tail=[nums[0]]$，表示目前为止长度为1的最长上升子序列的最小尾元素为$nums[0]$
 3. 遍历数组，对于$i$，遍历区间$[1,n)$：
 	+ 若$nums[i]>tail[-1]$，$tail[-1]$表示最后一个元素。若当前的数组元素比$tail$的最后一个元素大，将其加入$tail$。跳过后续步骤。
 	+ 若不满足，则在$tail$中找到第一个比他大的元素，替换掉。使用二分查找，查找替换位置。
 	+ 定义左界$l=0$，右界$r=len(tail)-1$
 	+ 进入循环，循环条件$l<=r$：
 		+ 定义$mid=(l+r)//2$
 		+ 若$nums[i]<=tail[mid]$，更新右界：$r=mid-1$
 		+ 否则，$l=mid+1$ 
 	+ 替换，$tail[l]=nums[i]$
 4. 返回$tail$的长度。

	  

	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
### 复杂度分析
 - 时间复杂度：$O(nlog(n))$
 - 空间复杂度：$O(n)$

### Python
```python
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if(not nums):
            return 0
        n=len(nums)
        if(n<2):
            return n
        tail=[nums[0]]
        for i in range(1,n):
            if(nums[i]>tail[-1]):
                tail.append(nums[i])
                continue
            l=0
            r=len(tail)-1
            while(l<=r):
                mid=(l+r)//2
                if(tail[mid]>=nums[i]):
                    r=mid-1
                else:
                    l=mid+1
            tail[l]=nums[i]
        return len(tail)
```