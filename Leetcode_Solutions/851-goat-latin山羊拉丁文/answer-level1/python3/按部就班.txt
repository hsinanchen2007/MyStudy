```
class Solution:
    def toGoatLatin(self, S: str) -> str:
        s_list=S.split(' ')
        rs=''
        m=['a','A','e','E','i','I','o','O','u','U']
        for i in range(s_list.__len__()):
            if s_list[i][0] in m:
                rs=rs+s_list[i]+'ma'
            else:
                tmp=s_list[i][1:]+s_list[i][0]
                rs=rs+tmp+'ma'
            for j in range(1,i+1+1):
                rs=rs+'a'
            rs=rs+' '
        rs=rs.rstrip(' ')
        return rs
```