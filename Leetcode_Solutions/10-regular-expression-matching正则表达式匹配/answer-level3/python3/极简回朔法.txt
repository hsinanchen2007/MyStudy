```
# -*- coding: utf-8 -*-

# Author: Cynthia

"""
    题目分析: 只含a-z . *的正则匹配; 字符串和模式都可能为空
    比如: caab, ca*b, 匹配上; .很好处理, 匹配任何字母即可, 关键是*, 要和前一个字符一起考虑
"""
"""
    方法1, 贪心算法
    caab匹配ca*b, 非x*的如果首字符匹配上各往后移一位; x*的按匹配0个和n个去贪心, 走不通回溯
    再试另外一种可能性; 实际写递归的的时候, 可以每次都试0次和1次, 也能达到匹配0-n次的目的
"""


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        def rf(s: str, p: str):
            # 如果p到头了, 没匹配完s, 则返回False
            # 如果s到头了, p没到头, 只有x*的形式才能匹配上, 后面处理
            if not p: return not s
            # 无论是x还是x*都需要知道首字符是否匹配上, 建议单拎出来
            fmatch = bool(s) and p[0] in {'.', s[0]}
            # 情况1, 非x*
            if not p[1:] or p[1] != '*':
                return fmatch and rf(s[1:], p[1:])
            # 情况2, x*, 匹配上可以一直往后匹配; 无论匹配上没上都可以匹配0次
            return fmatch and rf(s[1:], p) or rf(s, p[2:])

        return rf(s, p)


s = Solution()
print(s.isMatch("", "a*a"))

```
