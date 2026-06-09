### 解题思路
直接用int函数的将两个输入转为十进制，进行计算后利用bin函数转换回来就行~

### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        a = int(a, 2)
        b = int(b, 2)
        return bin(a + b)[2:]
```