```
class Solution:
    def myAtoi(self, str: str) -> int:
        elements=['1','2','3','4','5','6','7','8','9','0']
 
        result=[]
        for i in range(len(str)):
            if len(result)==0:
                if str[i]==' ':
                    continue
                elif str[i] not in elements and str[i] not in ['+','-']:
                    return 0
                else:
                    result.append(str[i])
            else:
                if str[i] in elements:
                    result.append(str[i])
                else:
                    break

        
        if not result or (len(result)==1 and result[0] in ['+','-']):return 0

        m=int(''.join(result))
        if m<-2**31:
            return -2**31
        elif m>2**31 - 1:
            return 2**31-1
        else:
            return m
```
