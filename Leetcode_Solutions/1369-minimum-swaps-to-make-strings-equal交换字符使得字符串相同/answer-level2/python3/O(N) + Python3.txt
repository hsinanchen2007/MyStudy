![图片1.png](https://pic.leetcode-cn.com/9e7cab981d385e0a432b93bfc195352e419327c81c082aba0cba0eb628c27c85-%E5%9B%BE%E7%89%871.png)

只要统计xy和yx的数量即可。Ex1和Ex2已经告诉我们这两种情况分别需要swap一次和两次。最后只要判断下xy和yx的奇偶既可，要么同为奇数（多加个2），要么同为偶数，否则不可能。

```
class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        n, xy, yx = len(s1), 0, 0
        for i in range(n):
            if s1[i] == 'x' and s2[i] == 'y': xy += 1
            elif s1[i] == 'y' and s2[i] == 'x': yx += 1
        if xy % 2 and yx % 2:
            return xy // 2 + yx // 2 + 2
        elif not xy % 2 and not yx % 2:
            return xy // 2 + yx // 2
        else: return -1
```


