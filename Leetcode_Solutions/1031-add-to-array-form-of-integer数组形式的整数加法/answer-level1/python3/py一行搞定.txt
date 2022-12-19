### 解题思路


### 代码

```python3
class Solution:
    def addToArrayForm(self, A, K) :
        return [int(i) for i in list(str(int(''.join([str(i) for i in A])) + K))]
```