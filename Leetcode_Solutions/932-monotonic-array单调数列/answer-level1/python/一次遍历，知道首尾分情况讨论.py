```
class Solution(object):
    def isMonotonic(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        #知道首尾大小就知道是递增还是递减了
        tail = A[-1]
        head = A[0]
        for i in range(len(A) - 1):
            #递减
            if head > tail and A[i] < A[i+1]:
                return False
            #递增
            elif head < tail and A[i] > A[i+1]:
                return False
            #水平直线
            elif head == tail  and A[i] != A[i+1]:
                return False
                
        return True
```
