![image.png](https://pic.leetcode-cn.com/f85b2be6f22e8eaf5dac1aa052a053bfc255e2c648d44c1e5bbfd5e520de077c-image.png)


```
'''
递归对模式字符和子字符串进行匹配，如果出现类匹配矛盾，即失败
只要有一种匹配方成功，即返回成功
'''

from collections import Counter
class Solution:
    def dfs(self, pat_pos, str_pos, pattern: str, s, m) -> bool:
        if pat_pos == len(pattern):
            return str_pos == len(s)

        if str_pos == len(s):
            return False

        pat_ch = pattern[pat_pos]
        if m[pat_ch][1]:
            if s[str_pos: str_pos + len(m[pat_ch][0])] != m[pat_ch][0]:
                return False

            if self.dfs(pat_pos+1, str_pos + len(m[pat_ch][0]), pattern, s, m):
                return True

        else:
            for end in range(str_pos+1, len(s)+1):
                pat = s[str_pos: end]
                pat_ch_cnt = Counter(pattern[pat_pos:])[pat_ch]
                # pat出现的次数必须大于等于pat_ch_cnt， 提前剪枝
                idx = str_pos
                pat_cnt = 0
                while True:
                    idx = s.find(pat, idx)
                    if idx != -1:
                        pat_cnt += 1
                        idx += len(pat)
                    else:
                        break

                if pat_cnt < pat_ch_cnt:
                    continue

                flag = True
                for k, v in m.items():
                    if v[1] and v[0] == pat and k != pat_ch:
                        # 字符串已经被其他的模式字符选中了，不能重复选
                        flag = False
                if not flag:
                    continue

                m[pat_ch][0] = pat
                m[pat_ch][1] = True

                if self.dfs(pat_pos+1, end, pattern, s, m):
                    m[pat_ch][1] = False
                    return True

                m[pat_ch][1] = False

        return False

    def wordPatternMatch(self, pattern: str, str: str) -> bool:
        m = {ch: ['', False] for ch in 'abcdefghijklmnopqrstuvwxyz'}  # 记录每个patter对应的字符串和该patter是否当前有效
        return self.dfs(0, 0, pattern, str, m)
```
