二进制中有0需要1步操作，有1需要2步操作，最后一个1只需要1步。

```
class Solution:
    def numberOfSteps (self, num: int) -> int:
        if num == 0:
            return 0
        res = 0
        a = 3 if num < 0 else 2
        for i in bin(num)[a:]:
            res += 2 if i == '1' else 1

        return res-1
```
