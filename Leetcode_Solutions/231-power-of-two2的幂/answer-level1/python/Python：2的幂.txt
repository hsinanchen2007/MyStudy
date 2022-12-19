### 解题思路
之前有一道数1的题，用了二进制，但是没有使用count，经大佬指点，这次使用一下
2的幂的特点就是二进制只有一位为1

### 代码

```python3
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return True if n>0 and bin(n).count('1')==1 else False
```