### 解题思路
首先是对题目的理解，它是要返回最长的对称子串。
对称子串的话要么是偶数对称，要么是奇数对称。
这就是我的设计思路，代码中可见。
细节和测试很重要。

### 代码

```python3
# 基准，前后扫描
class Solution:
    def priorBackScan(self, s, length, prior, back):
        duichen_len = 0
        while prior >= 0 and back < length:
            if s[prior] == s[back]:
                duichen_len += 2
                prior -= 1
                back += 1
            else:
                break
        return duichen_len

    def longestPalindrome(self, s: str) -> str:
        length = len(s)
        if length == 0:
            return s
        max = 1
        max_begin = 0
        max_end = 0

        for i in range(0,length):
            cur_len = 1
            begin = i
            end = i

            # 以i为左基准
            # 1.得对称长度
            duichen_len = self.priorBackScan(s, length, i, i+1)
            # 2.根据cur_len可得begin,end,cur_len
            if duichen_len > 0:
                half = int(duichen_len/2)
                begin = i - half + 1
                end = i + half
                cur_len = duichen_len

            # 以i为中间基准，扫描两边
            duichen_len = self.priorBackScan(s, length, i-1, i+1)
            if duichen_len + 1 > cur_len:
                half = int(duichen_len/2)
                begin = i - half
                end = i + half
                cur_len = duichen_len + 1

            if cur_len > max:
                max = cur_len
                max_begin = begin
                max_end = end

        return s[max_begin:max_end+1]
```