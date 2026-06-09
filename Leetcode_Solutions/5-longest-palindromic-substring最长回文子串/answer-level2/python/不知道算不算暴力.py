求最大值，就从最大开始迭代，只要找到一组值，就直接返回，此时就是最大子串
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        a = [i for i in range(len(s))]
        a.sort(reverse=True)
        for i in a:
            for j in range(len(s)-i+1):
                b = s[0+j:j+i]
                #print(b)
                if b==b[::-1]:
                    return b