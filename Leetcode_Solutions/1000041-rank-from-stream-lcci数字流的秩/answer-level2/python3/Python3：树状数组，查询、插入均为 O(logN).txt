树状数组的概念可参考 [315. 计算右侧小于当前元素的个数](https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/) 的题解。树状数组可用于求前缀和，因此适用于本题。

⚠️ 注意：在这个题目中，由于需要考虑 x=0 的情况，而如果直接将 x=0 传入 query 方法则会陷入死循环，故插入和查询时都将输入参数 + 1，防止 query 陷入死循环。

代码：

```
class BIT:

    def __init__(self, size):
        self.data = [0] * (size + 2)

    @staticmethod
    def __lowbit(x):
        return x & (-x)

    def update(self, index, delta):
        while index < len(self.data):
            self.data[index] += delta
            index += self.__lowbit(index)

    def query(self, index):
        ret = 0
        while index > 0:
            ret += self.data[index]
            index -= self.__lowbit(index)
        return ret

class StreamRank:

    def __init__(self):
        self.data = BIT(50000)

    def track(self, x: int) -> None:
        self.data.update(x + 1, 1)

    def getRankOfNumber(self, x: int) -> int:
        return self.data.query(x + 1)

```
