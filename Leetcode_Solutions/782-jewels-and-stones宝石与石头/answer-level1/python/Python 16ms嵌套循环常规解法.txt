class Solution(object):
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        r=0
        for i in S:
            for j in J:
                if i==j:
                    r=r+1
                    break
        return r