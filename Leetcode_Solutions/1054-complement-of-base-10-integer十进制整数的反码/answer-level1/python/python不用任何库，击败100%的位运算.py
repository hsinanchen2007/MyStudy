### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def bitwiseComplement(self, N):
        """
        :type N: int
        :rtype: int
        """
        if N==0:
            return 1
        i=0
        for i in range(32):
            if 2**i<=N<2**(1+i):
                print(2**(1+i)-1)
                return N^(2**(1+i)-1)
```