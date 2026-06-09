class Solution(object):    
    def CheckPermutation(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        from collections import Counter
        if Counter(s2) == Counter(s1):
            return True
        return False

    def check_permutation(self, s1, s2):
        if sorted(s1) == sorted(s2):
            return True
        return False



仍然是用两种方法：
1.空间换时间，空间复杂度O(N+M),时间复杂度O(max(N,M))
2.时间换空间，空间复杂度O(1),时间复杂度O(NlogN),python的 内置函数sorted使用的是timesort,时间复杂度即为O(NlogN)
