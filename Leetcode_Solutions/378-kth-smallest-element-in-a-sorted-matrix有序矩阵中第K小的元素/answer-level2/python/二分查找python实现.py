class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        left = matrix[0][0]
        right = matrix[-1][-1]
        
        while left < right:
            mid = (left+right) // 2
            print('mid:%d' %(mid))
            num = sum(bisect.bisect_right(row , mid) for row in matrix)
            #bisect.bisect_right(row, mid)计算row中元素值<=mid的数量
            print('num:%d' %(num))
            if num < k:
                left = mid+1
            else:
                right = mid 
        return left
        