### 解题思路
转十进制进行运算，再转成二进制

### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:

        return str(bin(int(str(a),2)+int(str(b),2)))[2:]
```