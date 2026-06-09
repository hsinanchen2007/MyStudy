## 解法一 动态规划$O(n^2)$
定义$dp_i$为以$nums_i$结尾的LIS长度,那么状态转移方程为:
$$
    dp_i=min\{dp_j+1|存在j使得nums_j<nums_i\}\\
    如果上述集合为空,则dp_i=1
$$
```python
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        n=len(nums)
        dp=[1]*n
        for i in range(n):
            for j in range(i):
                if nums[j]<nums[i]:
                    dp[i]=max(dp[i],dp[j]+1)
        return max(dp)
```
## 解法二 贪心+二分查找$O(nlogn)$
我们玩一个纸牌游戏,由如下两个规则:
- 每一叠纸牌递减
- 新的牌可以单都构成一叠

### 现在如何获得最少的叠数呢?
采取**贪心**的策略,每次将当前牌放在**最靠左合适**的位置.例如
[4,10,4,3,8,9]采取上述策略
4   10    9 
4   8  
3
那么[3,8,9]就构成LIS(取每一叠的牌顶)
采用如上策略,可以发现,没一叠的牌顶有序,那么新来一张牌的时候,可以利用$二分查找$来找到$第一个>=当前牌$的位置
```python
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        tmp=[]
        for i in range(len(nums)):
            l,r=0,len(tmp)
            while l<r:
                mid=(l+r)//2
                if tmp[mid]>=nums[i]:
                    r=mid
                else:
                    l=mid+1
            if l==len(tmp):
                tmp.append(nums[i])
            else:
                tmp[l]=nums[i]
        return len(tmp)
```
