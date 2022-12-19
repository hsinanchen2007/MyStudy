class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        res = ""
        for word in s.split(" "):
            res += word[::-1] + " "
        return res.strip()