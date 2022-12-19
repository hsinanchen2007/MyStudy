![image.png](https://pic.leetcode-cn.com/bb252eb67ee4fb233a95c23445eefa79943ab0c34a14d3fa2a65102573a5dec4-image.png)


```
'''
先统计超出平均数量的字符的个数，滑动窗口查找最短的窗口能够包含多出来的字符
'''


from collections import Counter
class Solution:

    def isMatch(self, cnt, m):
        flag = True
        for key in m:
            if cnt[key] < m[key]:
                flag = False
                break
        return flag


    def balancedString(self, s: str) -> int:
        c = Counter(s)
        target = len(s) // 4

        m = {}
        for k, v in c.items():
            if v > target:
                m[k] = v - target

        if len(m) == 0:
            return 0

        l, r = 0, 0
        cnt = Counter()
        cnt[s[0]] += 1
        ans = 0x7fffffff

        while True:
            if self.isMatch(cnt, m):
                while self.isMatch(cnt, m):
                    ans = min(ans, r - l + 1)
                    if s[l] in m:
                        cnt[s[l]] -= 1
                    l += 1

                    if l == r:
                        break

            else:
                if r == len(s)- 1:
                    break

                r += 1
                if s[r] in m:
                    cnt[s[r]] += 1

        return ans
```



