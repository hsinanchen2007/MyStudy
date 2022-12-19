如果字符串的前缀 $S_{pre}$ 和后缀 $S_{suf}$ 相等，那么 $S_{pre}$ 和 $S_{suf}$ 的首尾字符必然相等，所以我们只需要设置两个指针 l 和 r，l 从前往后扫描寻找 S[-1]，r 从后往前扫描找 S[0]，然后每次找到了对应的字符，就比对 l 扫描过的字符串 ls 部分和 r 扫描过的字符串 rs 部分是否相等，如果相等，就保存起来；否则就继续扫描，那么扫描完成后就能找到最长的快乐前缀了。

```python
class Solution:
    def longestPrefix(self, s: str) -> str:
        l, r = 0, len(s) - 1 # 左右指针
        ls, rs = '', '' # 用于存储左右指针扫描过的字符
        ret = '' # 最长快乐前缀
        while l < len(s) and r >= 0:
            lmove, rmove = False, False # 用两个布尔变量控制左右指针是否应该移动
            if len(ls) == len(rs): 
                if ls == rs and ls != s: ret = ls # 如果前缀和后缀相等，保存为快乐前缀
                lmove = True
                rmove = True
            elif len(ls) < len(rs): lmove = True # 如果前缀比后缀短，那么移动左指针
            else: rmove = True # 否则移动右指针
                
            if lmove:
                while l < len(s) and s[l] != s[-1]: # 左指针负责寻找字符串中与字符串结尾字符相等的字符
                    ls += s[l]
                    l += 1
                ls += s[l]
                l += 1
            if rmove:
                while r >= 0 and s[r] != s[0]: # 右指针负责寻找字符串中与字符串开始字符相等的字符
                    rs = s[r] + rs
                    r -= 1
                rs = s[r] + rs
                r -= 1
        return ret
```