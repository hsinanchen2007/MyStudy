class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        lista=[]
        listb=[]
        
        self.A = A
        for i in range(len(A)):
            if A[i]%2 == 0:
                lista.append(A[i])
                
            else:
                listb.append(A[i])
                
        return lista+listb    