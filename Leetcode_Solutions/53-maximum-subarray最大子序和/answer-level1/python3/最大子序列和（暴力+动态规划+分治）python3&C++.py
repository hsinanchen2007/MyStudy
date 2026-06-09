题目链接：[https://leetcode-cn.com/problems/maximum-subarray/submissions/](https://leetcode-cn.com/problems/maximum-subarray/submissions/)

例子：
```
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
```
## 思路一：暴力法

对子数组的起始位置遍历一遍，对于每个起始位置，再向后遍历一遍找出对应的最大子数组和，最后再求出不同起始位置的最大子数组和的最大值
- 时间复杂度：需要两层循环O(n^2)
- 空间复杂度: O(n)

## 思路二：动态规划法

这里关键是如何表示状态，设dp[i]表示以第i个元素结尾的最优解序列的最大子序列和，根据测试例找规律得到的状态转移方程为dp[i] = max(dp[i-1]+nums[i],nums[i])，最后只需找出dp数组的最大值即为所求。若再设置一个head指针指向最优解序列的头结点，则当dp[i]更新为nums[i]时，head也同步更新为i，利用head指针和dp数组最大值的下标可确定最优解序列
- 时间复杂度：只需遍历一遍O(n)
- 空间复杂度：O(n)

python3实现：
```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # 参考https://leetcode-cn.com/problems/maximum-subarray/solution/dong-tai-gui-hua-qiu-jie-zui-da-zi-xu-he-by-hikes
        dp = [nums[0]]
        head = 0
        for i in range(1, len(nums)):
            if dp[i-1]+nums[i] > nums[i]:
                dp.append(dp[i-1]+nums[i])
            else:
                dp.append(nums[i])
                head = i
        # res, end = dp[0], 0
        # for i in range(1, len(dp)):
        #     if dp[i] > res:
        #         res = dp[i]
        #         end = i
        # print(nums[head:end+1])
        return max(dp)
```
C++实现：
```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int len = nums.size();
        int i, head = 0;
        vector<int> dp(len);
        dp[0] = nums[0];
        for(i=1; i<len; ++i)
            dp[i] = dp[i-1]>0 ? dp[i-1]+nums[i]:nums[i];
        int res = dp[0];
        for(i=1; i<len; ++i)
            if(dp[i]>res) res = dp[i];
        return res;
        }
}
```
**优化空间复杂度到O(1)**

对python版，直接利用原数组保存dp数组的各值（参考https://leetcode-cn.com/problems/maximum-subarray/comments/39601）
```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        for i in range(1, len(nums)):
            nums[i] = nums[i] + max(nums[i-1], 0) # 相当于dp[i-1]>0就加上当前的元素值作为dp[i]，否则dp[i]=nums[i]
        return max(nums)
```
对C++版，直接用两个变量分别保存当前最优解序列的最优解以及全局最优解
```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int sum = 0;
        for(auto num:nums)
        {
            if(sum>0) //如果当前和大于0，那么最优解序列还没完
                sum += num;
            else //否则最优解序列从下一个元素开始重新算
                sum = num;
            res = res>sum ? res:sum;
        }
        return res;
    }
}
```
## 思路3：分治法

子序列和最大的要么出现在左半边，要么出现在右半边，要么出现在中间。对于中间的情况，分别从mid向左和mid+1向右计算最大子序列和然后加起来
- 时间复杂度：不难得出T(n)=2T(n/2)+n,根据该递推公式，每递归一次，就会增加一个n，因为总共会递归logn次，所以复杂度应为nlog(n)
- 空间复杂度：O(1)

python3实现
```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # 分治法：子序列和最大的要么出现在左半边，要么出现在右半边，要么出现在中间。对于中间的情况，分别从mid向左和mid+1向右计算最大子序列和然后加起来，参考https://leetcode-cn.com/problems/maximum-subarray/solution/bao-li-qiu-jie-by-pandawakaka
        n = len(nums)
        if n == 1: #递归终止条件
            return nums[0]
        maxLeft = self.maxSubArray(nums[0:n//2])
        maxRight = self.maxSubArray(nums[n//2:n])
        
        midLeftSum,curSum = nums[n//2-1], nums[n//2-1]
        for i in range(n//2-2, -1, -1):
            curSum = curSum + nums[i]
            if curSum > midLeftSum:
                midLeftSum = curSum
        
        midRightSum, curSum = nums[n//2], nums[n//2]
        for i in range(n//2+1, n):
            curSum = curSum + nums[i]
            if curSum > midRightSum:
                midRightSum = curSum
        
        return max(maxLeft, maxRight, midLeftSum+midRightSum)
```
## 总结
综合来看，此题用动态规划来解是最简单高效的，但该题用动态规划解时与常见的动态规划问题不太一样。背包问题、切钢筋问题、插入最少字符变回文串问题的最优解均直接为某个状态值，而该题的最优解则是所有状态值中的最佳值，因此状态（以当前元素结尾的最优子数组的最大和）不是那么容易能想到（我自己就没想出来，关于动态规划中如何比较准确地确定状态欢迎网友交流讨论）。