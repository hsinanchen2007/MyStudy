### 解题思路
防止i+1超出索引，就在后面加了无长度的空串

### 代码

```python
class Solution(object):
    def reverseBits(self, num):
        a=bin(num)[2:].split('0')
        L=len(a)
        a.append('')
        b=[]
        for i in range(L):
            b.append(len(a[i]+a[i+1])+1)
        return max(b)         
```