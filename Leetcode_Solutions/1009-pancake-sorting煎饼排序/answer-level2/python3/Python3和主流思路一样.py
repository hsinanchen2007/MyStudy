从末端点开始，对每个元素进行两次的翻转操作，使之在正确的位置上

class Solution(object):
    def pancakeSort(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        M=[]
        M[:]=A
        M.sort()
        TA=[]
        for i in range(-1,-len(A)-1,-1):
            if A[i]==M[i]:
                continue
            else:
                small=A.index(M[i])+1
                TA.append(small)
                A[:small]=A[:small][::-1]
                big=len(M)+i+1
                TA.append(big)
                A[:big]=A[:big][::-1]
        return TA