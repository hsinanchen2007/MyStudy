 **抖个机灵***
1. 先把 a,b用bin(数，原本的进制)转为二进制
2. 得到a+b的二进制数
3. 将二进制数转为字符串
4. 截取字符串的索引为2的元素到最后（*前两位为0b所以要截取*）

```
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        a,b=int(a,2),int(b,2)
        ans=bin(a+b)
        ans=str(ans)
        ans=ans[2:]
        return ans
```
