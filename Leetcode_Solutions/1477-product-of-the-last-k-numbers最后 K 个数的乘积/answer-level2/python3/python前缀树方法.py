维护了一个乘积前缀树，同时维护一个数组存放0所在的位置
```
class ProductOfNumbers:

    def __init__(self):
        self.prefixTree = [1]    # 前缀树初始化
        self.number_0 = [-1]    # 初始化，默认0的位置是-1

    def add(self, num: int) -> None:
        if num == 0:
            self.number_0.append(len(self.prefixTree))  # 纪录'0'所在的位置

        if self.prefixTree[-1] == 0:
            self.prefixTree.append(num)
        else:
            self.prefixTree.append(self.prefixTree[-1]*num)

    def getProduct(self, k: int) -> int:
        if len(self.prefixTree)-k <= max(self.number_0):    # 前k个区间内包含0
            return 0
        # 前k个区间不包含0
        # 如果倒数第k-1个是0，那么直接返回self.prefixTree[-1]
        if self.prefixTree[-k-1] == 0: return self.prefixTree[-1]
        # 否则，返回self.prefixTree[-1] // self.prefixTree[-k-1]
        else:
            return self.prefixTree[-1] // self.prefixTree[-k-1]
```
