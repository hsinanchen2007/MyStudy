### 解题思路
此处撰写解题思路
python 写的比较方便
### 代码

```python3
class Solution:
    def hammingWeight(self, n: int) -> int:
        s = bin(n)[2:]
        return s.count('1',0,len(s))
```