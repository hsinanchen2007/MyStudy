### 解题思路
转为字符串进行求解

### 代码
'''
python
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        if x >= 0:
            d = ""
            strx = str(x)
            for i in range(len(strx)):
                d = strx[::-1]
            return d == strx
'''