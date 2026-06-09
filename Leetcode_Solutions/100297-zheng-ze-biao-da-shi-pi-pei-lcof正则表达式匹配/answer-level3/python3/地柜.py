```
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        def judge(indexs, indexp):
            if indexs == len(s) and indexp == len(p): return True 
            if indexs == len(s):
                while indexp<len(p)-1 and  p[indexp+1] =='*': indexp+=2
                if indexp != len(p): return False
                else: return True
                
            if indexs == len(s) or indexp == len(p): return False
            if p[indexp] in [s[indexs], '.']:
                if indexp < len(p)-1 and p[indexp+1] == '*':
                    return judge(indexs+1, indexp) or judge(indexs, indexp+2)
                else:
                    return judge(indexs+1, indexp+1)
            else:
                if indexp < len(p)-1 and p[indexp+1] == '*':
                    return judge(indexs, indexp +2)
                else:
                    return False
        return judge(0,0)
```

```
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # def judge(indexs, indexp):
        #     if indexs == len(s) and indexp == len(p): return True 
        #     if indexs == len(s):
        #         while indexp<len(p)-1 and  p[indexp+1] =='*': indexp+=2
        #         if indexp != len(p): return False
        #         else: return True
                
        #     if indexs == len(s) or indexp == len(p): return False
        #     if p[indexp] in [s[indexs], '.']:
        #         if indexp < len(p)-1 and p[indexp+1] == '*':
        #             return judge(indexs+1, indexp) or judge(indexs, indexp+2)
        #         else:
        #             return judge(indexs+1, indexp+1)
        #     else:
        #         if indexp < len(p)-1 and p[indexp+1] == '*':
        #             return judge(indexs, indexp +2)
        #         else:
        #             return False
        # return judge(0,0)

 
        import numpy as np 
        dp = np.zeros(shape=(len(s)+1, len(p)+1))
        dp[-1,-1] = 1
        for  i in range(len(s), -1 , -1):
            for j in range(len(p)-1, -1 , -1):
                match = i < len(s) and p[j] in [s[i],'.']
                if j+1< len(p) and p[j+1] == '*':
                    dp[i,j] =  match and dp[i+1, j] or dp[i,j+2]
                else:
                    dp[i,j] =  match and dp[i+1, j+1]
        return bool(dp[0,0])
```
