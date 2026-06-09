![image.png](https://pic.leetcode-cn.com/aae09784e5bc6c655e9cf48050f8a925eb33f3c26fc4535323fa94b336068250-image.png)


```
'''
滑动窗口统计字符计数值
'''

from collections import Counter
class Solution:
    def numKLenSubstrNoRepeats(self, S: str, K: int) -> int:
        s = set(S[:K])       # 统计窗口出现的字符
        c = Counter(S[:K])   # 统计窗口出现的字符计数

        cnt = 1 if len(s) == K else 0
        for i in range(K, len(S)):
            c[S[i]] += 1
            if c[S[i]] == 1:
                s.add(S[i])

            c[S[i-K]] -= 1
            if c[S[i-K]] == 0:
                s.remove(S[i-K])

            if len(s) == K:
                cnt += 1

        return cnt
```
