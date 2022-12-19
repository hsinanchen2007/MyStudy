```
class Solution:
    def binaryGap(self, N: int) -> int:
        str_ = bin(N)
        ans = 0
        tmp = []
        for i in range(len(str_)):
            if str_[i] == '1':
                tmp.append(i)
        for i in range(len(tmp) - 1):
            if tmp[i + 1] - tmp[i] > ans:
                ans = tmp[i + 1] - tmp[i]
        return ans
```
