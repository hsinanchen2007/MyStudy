### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def hammingWeight(self, n: int) -> int:
        res = 0
        tmp = str(bin(n))
        for i in range(len(tmp)):
            if tmp[i]=='1':
                res+=1
        return res
```