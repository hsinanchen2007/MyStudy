## 思路
- - 先按照＋号切分
- 然后对切分后的元素调用sub_calculate方法，它是各递归的方法
```
class Solution:
    def calculate(self, s: str) -> int:
        plus_elem = [self.sub_calculate(x.strip()) for x in s.split('+')]
        return int(sum(plus_elem))
    def sub_calculate(self,s: str)->int:
        if '-' in s:
            minus_elem = [x.strip() for x in s.split('-')]
            res = self.sub_calculate(minus_elem[0])
            for i in range(1,len(minus_elem)):
                res = res-self.sub_calculate(minus_elem[i])
            return res
        elif '*' in s or '/' in s:
            s = s.strip()
            i = len(s)-1
            while i>=0 and s[i]!='/' and s[i]!='*':
                i-=1
            if s[i]=='*':
                return self.sub_calculate(s[:i].strip())*self.sub_calculate(s[i+1:].strip())
            elif s[i]=='/':
                return int(self.sub_calculate(s[:i].strip())/self.sub_calculate(s[i+1:].strip()))
        elif s.isdigit():
            return int(s.strip())
```
