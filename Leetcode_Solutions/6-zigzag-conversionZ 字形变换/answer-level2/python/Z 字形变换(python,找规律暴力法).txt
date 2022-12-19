### 解题思路
暴力找规律，一行一行的把数字输出。

### 代码

```python3
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if not s:
            return ""
        if numRows<2 or len(s)<=numRows:
            return s

        stem=""
        h=2*numRows-2 
        ktem1=len(s)//h 
        ktem2=len(s)%h 

        if ktem1==0:
            stem=stem+s[0]
            for j in range(1,numRows-1): 
                if j<ktem2:
                    stem=stem+s[j]
                if j+(numRows-j-1)*2<ktem2:
                    stem=stem+s[j+(numRows-j-1)*2] 
            stem=stem+s[numRows-1]
            return stem
       
        for i in range(ktem1):
            stem=stem+s[h*i+0]
        if 0<ktem2:
            stem=stem+s[h*(i+1)+0]    
        for j in range(1,numRows-1): 
            for i in range(ktem1): 
                stem=stem+s[h*i+j]
                stem=stem+s[h*i+j+(numRows-j-1)*2]
            if j<ktem2:
                stem=stem+s[h*(i+1)+j]
            if j+(numRows-j-1)*2<ktem2:
                stem=stem+s[h*(i+1)+j+(numRows-j-1)*2] 


        for i in range(ktem1):
            stem=stem+s[h*i+numRows-1]  #J 2 I 2       
        if numRows-1<ktem2:
            stem=stem+s[h*(i+1)+numRows-1]
        return stem

```