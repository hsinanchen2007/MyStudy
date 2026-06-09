class Solution:
    def balancedStringSplit(self, s: str) -> int:
        m = 0  # m 用来统计L的数量
        n = 0  # n用来统计R的数量
        count = 0 # 用来统计平衡字符串的数量
        for i in range(len(s)):
            if (s[i] == 'L'):
                m += 1
            else:
                n += 1
            if (m == n):
                count += 1
                m = 0
                n =0
            continue
        return count