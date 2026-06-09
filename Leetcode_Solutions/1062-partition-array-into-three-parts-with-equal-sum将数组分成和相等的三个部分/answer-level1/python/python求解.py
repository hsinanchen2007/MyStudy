class Solution(object):
    def canThreePartsEqualSum(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        if(sum(A) %3):
            return False
        s = sum(A)/3
        s1=0
        num=0;
        i=0
        while(i<len(A)):
            s1 = s1 + A[i]
            if(s1==s):
                num = num+1
                s1=0
            i = i+1
            if(num >=2 and i<len(A)):
               return True 
        return False