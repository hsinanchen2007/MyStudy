### 解题思路
从小的开始，截成n、(n-1)。。。。。。1段，依次看能不能被长字符串整除

### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if len(str1) > len(str2):
            return self.commonSon(str1,str2)
        else:
            return self.commonSon(str2,str1)

    def commonSon(self,longStr,shortStr):
        r = ""
        for i in range(1,len(shortStr)+1):
            if self.canDivide(shortStr,shortStr[0:i]) and self.canDivide(longStr,shortStr[0:i]):
                if i > len(r):
                    r = shortStr[0:i]
        return r
    
    def canDivide(self,string,x):
        xlen = len(x)
        slen = len(string)
        if not (slen % xlen == 0):
            return False
        else:
            if x*int(slen/xlen) == string:
                return True
            else:
                return False

```