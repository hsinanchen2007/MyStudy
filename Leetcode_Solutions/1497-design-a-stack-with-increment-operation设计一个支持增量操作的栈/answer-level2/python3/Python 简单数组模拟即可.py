![image.png](https://pic.leetcode-cn.com/ffbacca9ec90f60131c177d37958ac2532f89c8f12b970ef129ebc6e469e331b-image.png)


```
class CustomStack:

    def __init__(self, maxSize: int):
        self.data = [0 for _ in range(maxSize)]
        self.pos = -1


    def push(self, x: int) -> None:
        if self.pos == len(self.data) - 1:
            return

        self.pos += 1
        self.data[self.pos] = x


    def pop(self) -> int:
        if self.pos == -1:
            return -1

        ans = self.data[self.pos]
        self.pos -= 1
        return ans


    def increment(self, k: int, val: int) -> None:
        for i in range(0, min(k, len(self.data))):
            self.data[i] += val
```
