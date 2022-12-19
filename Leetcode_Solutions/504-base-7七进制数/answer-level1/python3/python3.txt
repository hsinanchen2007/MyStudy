### 解题思路
对7取余数，和转二进制一样

### 代码

```python3
class Solution:
    def convertToBase7(self, num: int) -> str:
        if num==0:
            return "0"
        res=[]
        tmp=abs(num)
        while tmp!=0:
            res.append(str(tmp%7))
            tmp//=7
        print(res)
        return "-"+"".join(res[::-1]) if num<0 else "".join(res[::-1])
    
            


```