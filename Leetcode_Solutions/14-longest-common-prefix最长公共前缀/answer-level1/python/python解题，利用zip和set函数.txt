class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        rs = ''
        ziped = zip(*strs)
        for i in range(len(zip(*strs))):
            t_set = set(ziped[i])
            if i==0 and len(t_set) != 1:
                return rs
            elif len(t_set) == 1:
                rs = rs + ziped[i][0]
        return rs