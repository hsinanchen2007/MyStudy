```
class Solution:
    def minFlipsMonoIncr(self, S: str) -> int:
        N=len(S)
        N_0=S.count("0")  #total 0s
        n_0=0 #current 0s
        n_1=0
        res=N_0     #分割线指的是01的分割线，如果在最前面分割，eg：|11100

        for i in range(len(S)):
            if S[i]=="0":
                n_0+=1
            else:
                n_1+=1
            res=min(res,n_1+(N_0-n_0))  #在i位置后面做分割
        return res
```
