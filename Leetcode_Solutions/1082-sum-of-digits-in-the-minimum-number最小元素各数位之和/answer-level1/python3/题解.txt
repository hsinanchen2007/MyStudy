### 解题思路
python 题解

### 代码

```python3
class Solution:
    def sumOfDigits(self, A: List[int]) -> int:
        min_num=min(A)
        N=len(str(min_num))
        he=0
        for i in str (min_num):
            he+=int(i)
        return 1-he%2
```