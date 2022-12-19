class Solution(object):
    def minAddToMakeValid(self, S):
        """
        :type S: str
        :rtype: int
        """
        s1 = []
        s2 = []
        for s in S:
            if s == '(':
                s1.append(s)
            elif s == ')' and s1:
                s1.pop()
            else:
                s2.append(s)
        return len(s1)+len(s2)