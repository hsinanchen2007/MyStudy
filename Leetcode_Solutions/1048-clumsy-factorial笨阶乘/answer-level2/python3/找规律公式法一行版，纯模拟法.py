![image.png](https://pic.leetcode-cn.com/b85610b08697ecf7ac4985c7d8789b5f79bcc2d136ef7796a7ebd29cccd4c56c-image.png)


公式法当然快：

```
class Solution:
    def clumsy(self, N: int) -> int:
        return (N + [1, 2, 2, -1][N % 4]) if N > 4 else [7, 1, 2, 6][N % 4]
```

连前四项都没有的纯模拟，也不算太慢，80ms左右：

```
class Solution:
    def clumsy(self, N: int) -> int:
        ans = 0
        t = N
        while N > 0:
            if N > 1:
                N -= 1
                t *= N
            else:
                return ans + t
            if N > 1:
                N -= 1
                t = int(t / N)
                ans += t
            else:
                return ans + t
            if N > 1:
                N -= 1
                ans += N
            else:
                return ans
            if N > 1:
                N -= 1
                t = -N
            else:
                return ans
```
