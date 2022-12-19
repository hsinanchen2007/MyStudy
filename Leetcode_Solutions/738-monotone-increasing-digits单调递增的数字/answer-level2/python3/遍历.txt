从左往右一轮遍历，如果当前位小于前位，则停止遍历；再往前遍历，直至前两位不等，则将这两位中的后一位减1，然后将后续位均变为9即可。
```
class Solution:
    def monotoneIncreasingDigits(self, N: int) -> int:
        s = str(N)
        res = []
        for num in s:
            res.append(int(num))
        for i in range(1, len(res)):
            if res[i] < res[i-1]:                      #往后遍历，寻找小于前一位的数字
                while i > 1 and res[i-1] == res[i-2]:  #往前遍历，寻找大于前一位的数字
                    i -= 1
                res[i-1] -= 1                          #将该位减1，并将后续位均变为9
                for j in range(i, len(res)):
                    res[j] = 9
                break
        return int(''.join([str(num) for num in res]))
```
