### 解题思路
将一个数十进制展开，分别与另外一个数相乘就行了

### 代码

```python3
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        k=0
        res=0
        for i in range(len(num1)-1,-1,-1):
            cur=int(num1[i])
            res+=cur*int(num2)*(10**k)
            k+=1
        return str(res)
```