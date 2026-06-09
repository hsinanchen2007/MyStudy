
```
class Solution(object):
    def largestTimeFromDigits(self, A):
        """
        :type A: List[int]
        :rtype: str
        """
        res = []
        m_value = 0
        for i in range(4):
            for j in range(4):
                if i!=j:
                    for k in range(4):
                        if k!=i and j!=k:
                            l = 6-k-i-j                                      
                            value = A[i]*1000+A[j]*100+A[k]*10+A[l]
                            if value>=2400:continue
                            if (value/10)%10>=6:continue
                            if value>=m_value:
                                m_value=value
                                res = [A[i],A[j],A[k],A[l]]
                                
        if res:
            return str(res[0])+str(res[1])+":"+str(res[2])+str(res[3])
        else:
            return ""
```
