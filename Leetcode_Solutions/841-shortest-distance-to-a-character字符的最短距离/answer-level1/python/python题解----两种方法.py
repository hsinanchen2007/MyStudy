```
class Solution(object):
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        #解法一（非常好理解的便利方法）
        L = []
        result = []
        k = []
        for i in range(len(S)):
            if S[i] == C:
                L.append(i)
        for i in range(len(S)):
            for j in L:
                k.append(abs(j-i))
            result.append(min(k))
            k = []
        return result
    
        #解法二（同官方题解）                
        prev = float('-inf')
        ans = []
        for i,x in enumerate(S):
            if x==C :
                prev = i
            ans.append(i-prev)
        prev = float('inf')
        for i in range(len(S)-1,-1,-1):
            if S[i] == C:
                prev = i
            ans[i] = min(ans[i], prev-i)
        return ans
```
