class Solution:
    def balancedStringSplit(self, s: str) -> int:
        balance = 0
        res = 0
        for ss in s:
            if ss == 'L':
                balance += 1
            elif ss == 'R':
                balance -= 1
            if balance == 0:
                res += 1
        return res
'''
抄来的，解题思路很巧妙，我的思路是先把字符串分割称为列表，然后计算列表的长度
其实并不需要这么麻烦，这道题的输出反馈是一个数字，一个结果，中间的过程只需要计数即可
'''