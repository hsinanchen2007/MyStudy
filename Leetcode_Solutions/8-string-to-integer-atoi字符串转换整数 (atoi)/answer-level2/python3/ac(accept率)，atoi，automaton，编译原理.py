### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def myAtoi(self, str: str) -> int:
        flag=None
        res=[]
        for c in str:
            if  c==' ' and not res and not flag:
                continue    
            elif c in '+-' and not res and not flag:
                flag=(1 if c=='+' else -1)
            
            elif c in '0123456789':
                res.append(c)
            else:
                break
        if not res:
            return 0
        res=(flag if flag else 1)*int(''.join(res))
        return res if -2**31<=res<=2**31-1 else (2**31-1 if res>0 else -2**31)
```