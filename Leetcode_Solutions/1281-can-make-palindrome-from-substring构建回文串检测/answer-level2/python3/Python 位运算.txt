![image.png](https://pic.leetcode-cn.com/01459bd91a9f46ce5db693f019a11f8d5a9c711f8e7389044847486309da67bf-image.png)


```
'''
位运算，每一位代表一个字符累计数量的奇偶性
通过字符计数的奇数值出现的次数可以判定最多
需要多少次交换才能得到回文串
'''

from typing import List
class Solution:
    def canMakePaliQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
        n = len(s)
        dp = [0 for _ in range(n)]
        dp[0] |= (1 << (ord(s[0])-ord('a')))
        for i in range(1, n):
            dp[i] = dp[i-1] ^ (1 << (ord(s[i]) - ord('a')))

        ans = []
        for start, end, times in queries:
            if start == 0:
                val = dp[end]
            else:
                val = dp[end] ^ dp[start-1]

            cnt = 0
            for i in range(26):
                if val & (1 << i):
                    cnt += 1

            if (end - start + 1) % 2 == 1:
                cnt -= 2
            cnt -= times * 2

            ans.append(cnt <= 0)
        return ans
```
