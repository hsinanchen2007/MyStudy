### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        a1=0
        b1=0
        for i in a:
            a1 =a1*2+int(i)
        for i in b:
            b1 =b1*2+int(i)
        return bin(a1+b1)[2:]
```