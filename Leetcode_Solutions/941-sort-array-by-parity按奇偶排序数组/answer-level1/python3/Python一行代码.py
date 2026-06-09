### 解题思路
一行Python，in-Place返回。

### Python3代码

```python
class Solution:
    def sortArrayByParity(self, A):
        return [a for a in A if not a % 2] \
             + [a for a in A if a % 2]
```