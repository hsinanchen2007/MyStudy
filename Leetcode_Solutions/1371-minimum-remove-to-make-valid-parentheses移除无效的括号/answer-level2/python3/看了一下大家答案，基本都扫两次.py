用比较自然的想法，先统计（和）的最小值作为limit,第二次遍历中如果先出现），看剩下的够不够填充。足够的话，limit不变，不够则limit-1..
```
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        ret=''
        m,n=s.count('('),s.count(')')
        limit=min(m,n)
        sp=n-limit
        zuo=0
        you=0
        for i in s:
            if i not in ['(',')']:
                ret+=i
            elif i=='(' and zuo<limit:
                ret+=i
                zuo+=1
            elif i==')' and you<limit and you<zuo:
                ret+=i
                you+=1
            elif i==')' and zuo==you:
                if sp==0:
                    limit-=1
                else:
                    sp-=1
        return ret
                
                
```
