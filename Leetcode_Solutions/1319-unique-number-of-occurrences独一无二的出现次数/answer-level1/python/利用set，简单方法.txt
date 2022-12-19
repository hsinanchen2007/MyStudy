class Solution(object):
    def uniqueOccurrences(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        arr_set = set(arr)
        count = []
        for i in arr_set:
            count.append(arr.count(i))
        return (True if len(set(count))==len(set(arr)) else False)