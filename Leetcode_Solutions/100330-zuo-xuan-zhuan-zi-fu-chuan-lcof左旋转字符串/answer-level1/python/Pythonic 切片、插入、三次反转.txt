```
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        arr = list(s)

        """ # 切片
        arr[:] = arr[n:] + arr[:n] """

        """ # 插入
        for i in range(n):
            arr.append(arr.pop(0)) """

        """ # 三次反转
        arr[:n] = arr[:n][::-1]
        arr[n:] = arr[n:][::-1]
        arr[:] = arr[::-1]"""

        return ''.join(arr) 
```
