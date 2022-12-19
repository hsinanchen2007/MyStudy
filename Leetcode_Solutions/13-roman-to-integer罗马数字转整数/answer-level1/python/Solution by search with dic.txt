### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        #lis=[]
        #for i in s:
         #  lis.append(i)
        #print(lis) 
        dic={"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000,"IV":4,"IX":9,"XL":40,"XC":90,"CD":400
        ,"CM":900}
        answer=0
        n=len(s)
        i=0
        #print(n)
        while (i<n):
            j=s[i]
            #print(j)
            group=s[i:i+2]
            #print(group)
            if group in dic:                
                answer=answer+dic[group]
                i=i+2
            else:
                answer=answer+dic[j]
                i=i+1
        return answer
```