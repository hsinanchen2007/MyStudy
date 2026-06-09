"""
@author : Joyce(ji)
@date :2019-10-24
"""
class Solution(object):
    def balancedStringSplit(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = 0
        count_L = 0
        count_R = 0
        flag = 0
        
        s_list = list(s)
        for s_ in s:
            if s_ == 'L':
                count_L += 1
            else:
                count_R += 1
            if count_L == count_R:
                count += 1
                total = count_L + count_R
                for i in range(flag, total):
                    print(s_list[i], end='')
                print(',', end=' ')
                flag = total
        return count