

运用动态规划的基本思想，假设dp[i]表示截至第i户所获得的最大金额，考虑到dp[i]的奇数项和偶数项均为非递减的，所以有dp[i]=max(dp[i-2],dp[i-3])+nums[i]。这样进行一次遍历后，时间复杂度为O(N)，并且只需比较倒数前两项就可获得整体的最大金额。
![微信截图_20200301102129.png](https://pic.leetcode-cn.com/f178099438a0fa7cb8e29bc1f0df0747b022f8d3fc0f4cab3cfadbc3cfcda3be-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200301102129.png)


![image.png](https://pic.leetcode-cn.com/8d651a36ceb79f983c1ae861caa3896a08fa4fcf66ee05a2fbfe8e7280ad4111-image.png)
