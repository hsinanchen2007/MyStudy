
![image.png](https://pic.leetcode-cn.com/7f82683300c44a958aadc33233778b323823ef840abcfebbd1ff81186b577e9d-image.png)

```
'''
可能次数最多的字符串一定是长度为minSize的字符串，maxSize参数是多余的
用长度为minSize的的窗口枚举子字符串，维护窗口中不同的字符个数，可以快速判断窗口
包住的子字符串是不是合法的，对合法的字符串出现次数进行计数，最后返回计数最大值即可
'''


class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        if minSize > len(s):
            return 0


        m = {ch:0 for ch in 'abcdefghijklmnopqrstuvwxyz'}
        str_cnt = {}
        diff_cnt = 0

        for i in range(minSize):
            m[s[i]] += 1
            if m[s[i]] == 1:
                diff_cnt += 1

        start, end = 0, minSize - 1
        while True:
            cur_str = s[start: end+1]
            if diff_cnt <= maxLetters:
                if cur_str not in str_cnt:
                    str_cnt[cur_str] = 0
                str_cnt[cur_str] += 1

            if end == len(s) - 1:
                break

            start, end = start+1, end+1
            m[s[start-1]] -= 1
            if m[s[start-1]] == 0:
                diff_cnt -= 1

            m[s[end]] += 1
            if m[s[end]] == 1:
                diff_cnt += 1

        return max(str_cnt.values()) if len(str_cnt) != 0 else 0
```
