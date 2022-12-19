### 解题思路
先将数组转成字符串合起来再转成整数+K，然后再逐个提出来。

### 代码

```python3
class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        return [int(i) for i in str(int(''.join(str(x) for x in A)) + K)]
```