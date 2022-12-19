### 解题思路
Python3模拟竖式乘法逐步实现,O(n^2),耗时较长

### 代码

```python3
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        la = len(num1)-1  
        res = []
        carry = 0
        for i in range(len(num1)):
            s = 0
            va = num1[la]
            lb = len(num2)-1 
            for j in range(len(num2)):
                vb = num2[lb]
                m = (int(va)*int(vb)+carry)%10
                carry = (int(va)*int(vb)+carry)//10
                s = s + m*(10**j)
                lb -= 1
            la -= 1
            if carry!=0:
                s = s + carry*(10**len(num2))
                carry = 0
            res.append(s*(10**i))
        s = 0
        for i in res:
            s = s + i
        return str(s)
```