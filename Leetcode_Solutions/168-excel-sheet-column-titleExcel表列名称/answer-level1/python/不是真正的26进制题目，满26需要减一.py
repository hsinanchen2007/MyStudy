```
class Solution:
    def convertToTitle(self, n: int) -> str:
        arr = []
        dic = dict(zip(range(1,27),[chr(i).upper() for i in range(97,123)]))
        while n:
            a = n % 26
            if a == 0:
                arr += ['Z']
                n = n // 26 - 1
            else:
                arr += [dic[a]]
                n = n // 26
        arr.reverse()
        return ''.join(arr)
```
