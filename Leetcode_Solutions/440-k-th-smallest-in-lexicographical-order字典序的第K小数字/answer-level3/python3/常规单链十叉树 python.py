按照字典序来堆放数字计数，用k来做指示
class Solution(object):
    def findKthNumber(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        cur=1
        k-=1
        
        while k>0:
            left,right=cur,cur+1
            node_num=0
            while left<=n:
                node_num+=min(right,n+1)-left
                left*=10
                right*=10
            if node_num<=k:
                k-=node_num
                cur+=1
            else:
                k-=1
                cur*=10
        return cur
