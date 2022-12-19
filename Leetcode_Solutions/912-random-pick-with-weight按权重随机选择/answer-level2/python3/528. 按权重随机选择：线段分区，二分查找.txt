
错误方法，查找时间是O(1),但最后两个用例会超内存：

```py
class Solution:

    def __init__(self, w: List[int]):
        self.a = []
        for i, j in enumerate(w):
            self.a += [i] * j                           #均匀建立数组
        self.n = len(self.a) - 1
        
    def pickIndex(self) -> int:
        return self.a[random.randint(0, self.n)]        #随机取下标
```

正确方法，按线段分区，然后二分查找，时间O(log(n))：

```py
class Solution:

    def __init__(self, w: List[int]):
        self.a = [0] * len(w)
        for i, j in enumerate(w):
            self.a[i] = self.a[i - 1] + j               #按线段标记坐标
            
    def pickIndex(self) -> int:
        return bisect.bisect_left(self.a, random.randint(1, self.a[-1]))
        #二分查找随机下标所在线段，注意要从1开始，否则如果权重w[0]是0的话，可能会随机到w[0]，返回的坐标是插在左边的坐标
```

![image.png](https://pic.leetcode-cn.com/f294d0f89c9edd285eb66a3e2bff6d4dbd1439857813fa8babf4fd6fc92bd547-image.png)
