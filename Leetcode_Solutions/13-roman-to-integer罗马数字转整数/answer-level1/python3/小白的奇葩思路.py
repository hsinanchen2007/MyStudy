class Solution:
    def romanToInt(self, s: str) -> int:
        A=1000*s.count('M')+500*s.count('D')+100*s.count('C')+50*s.count('L')+10*s.count('X')+5*s.count('V')+s.count('I')-2*s.count('IV')-2*s.count('IX')-20*s.count('XL')-20*s.count('XC')-200*s.count('CD')-200*s.count('CM')
        return A
不知道有字符转数字的方法，百度到了可以str.count子字符串的数量，凡是特殊的小权重在左边的均计算了两遍，因此减去两倍权重。大概和原始人摆小棍数小棍数量很类似吧……