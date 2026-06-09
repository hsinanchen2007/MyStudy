从后往前，遇到前一个大于后一个，前一个减去1，后面全部设置为9。

```
class Solution:
    def monotoneIncreasingDigits(self, N: int) -> int:
        digit = list(str(N))
        n = len(digit)
        for i in range(n - 1, 0, -1):
            if digit[i] < digit[i - 1]:
                digit[i - 1] = str(int(digit[i - 1]) - 1)
                digit[i:] = ['9'] * (n - i)  #此处能否再优化下？                    
        return int(''.join(digit))
```
