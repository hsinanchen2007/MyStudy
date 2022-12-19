```
class Solution:
    def countSubstrings(self, s: str) -> int:
        if len(s)==0: 
            return 0
        mx=0
        id=0
        count=0
        s1 = "".join((['#'+i for i in s]+['#']))
        len1 = len(s1)
        p = [0]*len1
        len1 = len(s1)
        
        for i in range(len1):
            
            p[i] =  min(p[2*id-i],mx-i+1) if mx>i else 1
            
            while p[i]+i<len1 and i-p[i]>=0 and s1[p[i]+i] == s1[i-p[i]]:
                p[i]+=1  #中心扩散
                
            if i + p[i] -1 > mx: #右边界mx更新,id中心更新
                id=i
                mx=p[i]+i-1
            
            count+= p[i]//2  #之所有用一半是因为以i为中心的两边是对称的
            
        return count
        
        
```
