求大神指导，我写的代码提交之后当字符串是'a'时结果错误，但是我用自己的电脑运行就可以得到正确结果

class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        if s=='':
            return 0
        ws=s.split(' ')
        i=len(ws)-1
        while i>=0:
            if ws[i]!=' ':
                return len(ws[i])
                break
            else:
                i=i-1

