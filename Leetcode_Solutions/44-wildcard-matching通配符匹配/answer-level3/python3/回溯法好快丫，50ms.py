# 回溯法，思路直接看代码吧，带注释
            
**代码：**
```
class Solution:  # 回溯
    def isMatch(self, s: str, p: str) -> bool:
        i = j = 0  # 用i索引s字符串，用j索引p字符串
        back_j = -1  # 记录p字符串中星号出现的位置
        match_i = 0  # 记录s字符串中从0到match_i位置都能匹配
        ls = len(s)
        lp = len(p)
        while i < ls:
            if j < lp and (s[i] == p[j] or p[j] == '?'):  # 若匹配，i和j往后移
                i += 1
                j += 1
            elif j < lp and p[j] == '*':  # *号出现，i不变，j记录
                back_j = j  # 记录星号的位置，方便回溯
                match_i = i  # 因为j处的'*'可以匹配s[i]，所以match_i = i
                j += 1  # i不变，j加1，看i能否和星号后面字符的匹配，若匹配则i和j后移，若不匹配则回溯
            elif back_j != -1:  # 回溯，j回到星号位置的下一个位置，i回到match_i的下一个位置
                j = back_j + 1
                match_i += 1  # match_i一直加1就是为了找到能和back_j的下一个位置匹配的，若匹配i和j各自加1继续往后移，若不匹配j继续回到                                  # back_j的下一个位置，match_i继续加1，直到match_i和back_j匹配，或者i溢出
                i = match_i
            else:  # 还没出现*,但s[i]和p[j]已经不匹配了，所以False
                return False
        return list(p[j:]).count('*') == len(p[j:])  # 此时s[:i]和p[:j]已经匹配，而且i==len(s)，若j也刚好溢出即p[j:]=[]，或者p[j:]的                                                       # 内容全是'*'，则s和p匹配 
```
**举例：** 
        p ='ab*c'
        s ='abcdcdc'
        1. 符号表示： 
            i = j = 0  # 用i索引s字符串，用j索引p字符串
            back_j = -1  # 记录p字符串中星号出现的位置
            match_i = 0  # 记录s字符串中从0到match_i位置都能匹配
        2. 匹配流程：
            i = 0, j = 0:  s[0] == p[0]，则 i = 1, j = 1
            i = 1, j = 1:  s[1] == p[1]，则 i = 2, j = 2
            i = 2, j = 2:  p[2] == '*'， 则 back_j = j, match_i = i (‘*’和‘c’可以匹配的哦)，j = 3 (匹配j的下一位置和i是否匹配)
            i = 2, j = 3:  s[2] == p[3], 则 i = 3, j = 4
            i = 3, j = 4:  j >= len(p)，则回溯, j = back_j+1, match_i += 1, i = match_i
            i = 3, j = 3:  s[3] != p[3], 则回溯，j = back_j+1, match_i += 1, i = match_i
            i = 4, j = 3:  s[4] == p[3], 则 i = 5, j = 4
            i = 5, j = 4:  j >=  len(p)，则回溯， j = back_j+1, match_i += 1, i = match_i
            i = 6, j = 3:  s[6] == p[3]，则 i= 7, j = 4
            i = 7, j = 4:  i >= len(s)，则结束
            且p[4:] = []，则返回True  
