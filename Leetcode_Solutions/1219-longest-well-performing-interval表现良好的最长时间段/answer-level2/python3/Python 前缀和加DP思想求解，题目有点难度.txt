![image.png](https://pic.leetcode-cn.com/cddce1c4d18f42a91285206f33ac4a3828c3d151067a097e9797eef9b277d06f-image.png)


```
'''
前缀和思想结合动态规划求解
大于8和小于等于8的数值映射成1和0
先用前缀和方式算出来0位置到i位置区间中1减0的数量

从左到右计算i为止结尾的最长区间长度，假设0到i位置1和0数量差为val,
如果val>=1 那0到i区间自然合法，否则，需要在i位置前面找1和0 差值
小于等于1-val第一次出现的位置，把这个位置以及它前面的部分砍掉
剩下的就是i位置结束的最长合法区间
再一次用前缀和，dp递推的思想
求1和0 差值小于等于x的状态出现一次的位置，其中x的数值只会是最小
的1和0数量差值到-1这个范围的值，其他的x对于问题求解没有意义


'''

from typing import List
class Solution:
    def longestWPI(self, hours: List[int]) -> int:
        m = {}      # 键是1和0数量的差值，值是该状态第一次出现的位置

        hours = [h > 8 for h in hours]
        sub_list = [0 for _ in range(len(hours))]
        zero_cnt, one_cnt = 0, 0
        min_sub = 0x7fffffff
        for i, h in enumerate(hours):
            one_cnt += 1 if h else 0
            zero_cnt += 0 if h else 1
            sub = one_cnt - zero_cnt
            sub_list[i] = sub

            min_sub = min(sub, min_sub)

            if sub not in m:
                m[sub] = i

        # dp[sub]表示1和0数量差值小于等于sub的状态第一次出现的位置
        dp = {}
        dp[min_sub] = m[min_sub]
        for sub in range(min_sub+1, 0, 1):
            if sub in m:
                dp[sub] = min(m[sub], dp[sub-1])
            else:
                dp[sub] = dp[sub-1]

        ans = 0
        for i, sub_val in enumerate(sub_list):
            if sub_val >= 1:
                ans = max(ans, i+1)
            else:
                target = sub_val - 1
                if target >= min_sub:
                    ans = max(ans, i - dp[target])

        return ans

```
