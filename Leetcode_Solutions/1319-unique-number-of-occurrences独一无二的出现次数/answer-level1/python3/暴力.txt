class Solution(object):
    def uniqueOccurrences(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        
        res = dict()
        for x in arr:
            res[x] = res.get(x,0) + 1
        
        return len(res.values()) == len(set(res.values()))