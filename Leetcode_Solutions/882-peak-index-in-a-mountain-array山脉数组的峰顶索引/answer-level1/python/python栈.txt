
class Solution(object):
    def peakIndexInMountainArray(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        stack = []
        for i in range(len(A)):
            if len(stack) == 0:
                stack.append(A[i])
            else:
                if stack[-1] < A[i]:
                    stack.pop()
                    stack.append(A[i])
                else:
                    stack.append(A[i])
        return A.index(stack[0])