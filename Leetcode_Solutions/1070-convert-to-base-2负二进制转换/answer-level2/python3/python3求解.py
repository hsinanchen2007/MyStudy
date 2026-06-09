class Solution:
    def baseNeg2(self, N: int) -> str:

        
        if(N == 0):
            return "0";
        
        result=''
        
        while N!=0:
            if N%2==0:
                result='0'+result
                N=N/(-2)
            else:
                result='1'+result
                N=(N-1)/(-2)
                
        return result