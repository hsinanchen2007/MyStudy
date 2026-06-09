```
class Solution(object):
    def partitionLabels(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        count = []
        end = 0
        last = 0
        
        for i,j in enumerate(S):
            if i+1<len(S) and j in S[i+1:]:
                t = S[i+1:].index(j)+i+1
                if end < t:
                    end = t
                if i == end:
                    count.append(i+1-last)
                    last = i+1
                
            else:
                if i>=end:
                    count.append(i+1-last)
                    last = i+1
        return count
            
        
```
