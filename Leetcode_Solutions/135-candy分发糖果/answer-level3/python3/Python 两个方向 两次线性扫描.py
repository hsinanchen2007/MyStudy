![image.png](https://pic.leetcode-cn.com/e60a32f222d2eaf8472776e72f37dc8ebd932d26756f92b85e9979878ae3a5f0-image.png)


```
'''
从左到右，从右到左分别扫描一遍
每次扫描找严格递增的子序列，序列第一个人给一个糖果，子序列后面的人分糖果依次加1，
遇到子序列只有一个人时候，需要看其后面的人是不是得分比它低，如果比它低，该人糖果
数必须为2，否则为1
最后每个人糖果数取两次扫描中较大值，这样每一个位置都保证了在两个方向上糖果数是满足
要求的，而且这样总糖果数一定最小
'''

from typing import List
class Solution:
    def candy(self, ratings: List[int]) -> int:

        n = len(ratings)
        dp = [0 for _ in range(n)]

        i = 0
        while i < len(ratings):
            j = i
            while j+1 < len(ratings) and ratings[j+1] > ratings[j]:
                j += 1

            if j != i:
                for k in range(1, j-i + 2):
                    dp[i+k-1] = k
            else:
                dp[i] =  2 if j + 1 < len(ratings) and ratings[j + 1] < ratings[j] else 1
            i = j+1

        i = n-1
        while i > 0:
            j = i
            while j-1 >= 0 and ratings[j-1] > ratings[j]:
                j -= 1

            if j != i:
                for k in range(1, i-j + 2):
                    dp[i-k+1] = max(dp[i-k+1], k)
            else:
                dp[i] = max(dp[i], 2 if j - 1 >= 0 and ratings[j - 1] < ratings[j] else 1)
            i = j - 1

        return sum(dp)
```
