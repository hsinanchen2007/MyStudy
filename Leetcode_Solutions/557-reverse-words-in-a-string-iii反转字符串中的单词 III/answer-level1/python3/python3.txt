class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        result = list()
        for i in s.split(' ') :
            result.append(i[::-1])
        return ' '.join(result)