遍历数字每一位，当前位比下一位大，则将后续数字全记为9，前面的数字减一后继续求最小单调增数。

```
class Solution:
    def monotoneIncreasingDigits(self, N: int) -> int:
        num = str(N)
        num = self.min_list(num)
        return int(num)

    def min_list(self, l):
        for i in range(len(l)-1):
            if l[i] > l[i+1]:
                return self.min_list(str(int(''.join(l[:i+1]))-1)) + (len(l)-i-1)*'9'
        return l
```
