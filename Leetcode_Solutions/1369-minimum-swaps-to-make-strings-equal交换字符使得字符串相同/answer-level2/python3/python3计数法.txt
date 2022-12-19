### 解题思路
只有计算不同的x和y各占多少即可，每两个x可以互相抵消，但是只剩一个x的时候需要2次才能消除。

### 代码

```python3
class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        if len(s1) != len(s2) or (s1.count('x')+s2.count('x'))%2:
            return -1
        stack_s1 = []
        for i in range(len(s1)):
            if s1[i]!=s2[i]:
                stack_s1.append(s1[i])
        x_num = stack_s1.count('x')
        y_num = stack_s1.count('y')
        result = x_num//2+y_num//2+x_num%2+y_num%2
        return result
```