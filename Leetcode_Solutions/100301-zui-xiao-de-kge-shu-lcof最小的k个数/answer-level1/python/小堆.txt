import heapq
class Solution(object):
    def getLeastNumbers(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
        """
        n=len(arr)
        a=[0]*k
        heapq.heapify(arr)
        for i in range(k):
            a[i]=heapq.heappop(arr)
        return a
        