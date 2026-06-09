```
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        n=len(strs)
        if n==0: 
            return ''
        elif n==1: 
            return strs[0]
        else:
            dict={}
            a_list=[] 
            for i in range(n):
                dict[strs[i]]=len(strs[i])
            list=dict.values()
            m=min(list)    #最短单词长度
            for j in range(m):
                a=strs[0][j]
                k=1
                while k<n:
                    if a==strs[k][j]:
                        k+=1
                        if k==n and a==strs[k-1][j]:
                            a_list.append(a)
                    else:
                        return "".join(a_list)
            return "".join(a_list)

```

          
                    
        