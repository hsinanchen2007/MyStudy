```
class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        # 符合贪婪，相对顺序是不变的
        pp = ''.join([p for p in pattern if p.isupper()])

        ans = []
        for  s in queries:
            dd = ''.join([q for q in s if q.isupper()])
            if dd != pp:
                ans.append(False)
                continue

            start,flag,pre  = -1, 0,0
            for p in pattern:
                start = s.find(p,start+1)
                if start < 0 :
                    flag = 1
                    ans.append(False)
                    break
                pre = start + 1   
           
            if flag == 0:
                    ans.append(True)
                

        return ans
```
