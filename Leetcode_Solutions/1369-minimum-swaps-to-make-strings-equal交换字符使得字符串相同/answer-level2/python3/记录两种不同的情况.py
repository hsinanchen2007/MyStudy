### 解题思路
就是for循环一次，记录两种不同的情况，再算一下就行

### 代码

```python3
class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        dif1 = 0
        dif2 = 0
        res =0
        for i in range(len(s1)):
            if s1[i] == "x":
                if s1[i] != s2[i]:
                    dif1 = dif1 + 1
            else:
                if s1[i] != s2[i]:
                    dif2 = dif2 + 1
        if (dif1 + dif2)%2 != 0:
            return -1
        else:
            return dif1%2 + dif2%2 + int(dif1/2) + int(dif2/2)
```