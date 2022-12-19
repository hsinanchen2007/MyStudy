
```
class Solution:
    def myAtoi(self, str: str) -> int:
        s = list(str)
        n =len(s)
        m = []
        for i in s:
            if i == ' ' and m==[]:
                continue
            elif (i == '+' or i=='-') and m == []:
                m.append(i)
            elif '0'<=i<='9':
                m.append(i)
            elif m != []:
                break
            else:
                return 0
        if m == []:
            return 0
        if m== ['+'] or m==['-']:
            return 0

        m = ''.join(m)
        m = int(m)
        if m>=0 and m<=2**31-1:
            return m
        if m>2**31-1:
            m = 2**31-1
            return m
        if m<0 and m>=-2**31:
            return m
        if m<-2**31:
            m = -2**31
            return m
```

