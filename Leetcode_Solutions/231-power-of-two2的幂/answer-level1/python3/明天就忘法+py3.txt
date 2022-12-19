### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        # n&(n-1)作用是把最低位的1变为0  如果是幂的话 10，100，1000类似这种 所以
        # n&(n-1)肯定等于0
        return n>0 and n&(n-1)==0
```