![2019-11-28_100530.png](https://pic.leetcode-cn.com/a98f71ddd931a493e921a57ade87240f9d635a60621618eaca38798a4e0efcc5-2019-11-28_100530.png)

```
class Solution:
    def findNthDigit(self, n: int) -> int:
        if n < 10: return n
        head, i = 0, 1
        while head < n:
            head, i = head + i*9*10**(i-1), i+1
        head, i = head - (i-1)*9*10**(i-2), i-1  # back to the previous...
        A = sum(9*10**(_-1) for _ in range(1, i))
        tail = n - head
        return int(str(A + tail//i + 1)[tail%i - 1]) if tail%i != 0 else int(str(A + tail//i)[i-1])
```
