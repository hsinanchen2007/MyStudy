#
# @lc app=leetcode.cn id=202 lang=python3
#
# [202] 快乐数
#
class Solution:
    def isHappy(self, n: int) -> bool:
        d = []
        a = str(n)
        c = 0
        while c != 1:
            b = 0
            for i in range(len(a)):
                b += int(a[i])**2
            a = str(b)
            c = int(a)
            
            if c == 1:
                return True
            if c in d:
                return False
            d.append(c)