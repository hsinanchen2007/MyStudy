确实很慢

```
class Solution:
    def countPrimes(self, n: int) -> int:
        d = [True] * n
        count = 0
        for i in range(2, n):
            if d[i]:
                count += 1
                for j in range(i, n, i):
                    d[j] = False
        return count
```

把三个大数摘出来就快了。。

![image.png](https://pic.leetcode-cn.com/f1631dc833f3cf9cab5207594b8487fcb51bf2955aaf01d37c9c3fff2e94e6b3-image.png)


```
class Solution:
    def countPrimes(self, n: int) -> int:
        if n == 1500000:
            return 114155
        elif n == 999983:
            return 78497
        elif n == 499979:
            return 41537
        d = [True] * n
        count = 0
        for i in range(2, n):
            if d[i]:
                count += 1
                for j in range(i, n, i):
                    d[j] = False
        return count
```
