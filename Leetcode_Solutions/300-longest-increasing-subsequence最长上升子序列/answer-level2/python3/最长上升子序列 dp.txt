### 解题思路
定义dp
dp[i]代表前i个数字的最长上升子序列, 其实准确的应该是以i为结尾的数字的最长上升子序列.(即第i个数字一定选)


### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        l = len(nums)
        dp = [1]*l
        for i in range(1, l):
            for j in range(i):
                dp[i] = max(dp[j]+1, dp[i]) if nums[i]>nums[j] else dp[i]
        # return dp[-1] #这是不对的! 因为最后一个数字不一定选!
        return max(dp)
```

参考这个老哥的题解 
解题思路：
降低复杂度切入点： 解法一中，遍历计算 dpdp 列表需 O(N)O(N)，计算每个 dp[k]dp[k] 需 O(N)O(N)。

动态规划中，通过线性遍历来计算 dpdp 的复杂度无法降低；
每轮计算中，需要通过线性遍历 [0,k)[0,k) 区间元素来得到 dp[k]dp[k] 。我们考虑：是否可以通过重新设计状态定义，使整个 dpdp 为一个排序列表；这样在计算每个 dp[k]dp[k] 时，就可以通过二分法遍历 [0,k)[0,k) 区间元素，将此部分复杂度由 O(N)O(N) 降至 O(logN)O(logN)。

作者：jyd
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-dong-tai-gui-hua-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

```
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        l, res = len(nums), 0 # res即为tail长度 (有效长度)
        tail = [0]*l
        for k in range(l):
            i, j = 0, res
            while i<j:
                m = (i+j)//2
                if tail[m]>=nums[k]: j=m
                else: i = m+1
            tail[i] = nums[k] # 这里的i虽然等于res, 但目前tail实际索引只到res-1, 因此赋值不会覆盖最后一个元素而是新开了一个元素
            if i==res: res+=1
        return res
```


