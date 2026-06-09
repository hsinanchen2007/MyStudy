### 解题思路
迭代计算

### 代码

```python3
class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        self.s = characters
        self.arr = list(range(combinationLength))           # 记录当前组合的下标，起始为[0, ..., combinationLength - 1]

    def next(self) -> str:
        n = len(self.arr)
        res = ''.join(self.s[i] for i in self.arr)
        for i in reversed(range(n)):
            if self.arr[i] != len(self.s) - n + i:          # 从后往前寻找第一个可前进的下标
                self.arr[i] += 1
                self.arr[i + 1:] = list(range(self.arr[i] + 1, self.arr[i] + n - i))    # 重置后续的下标
                break
        else:
            self.arr[0] += 1
        return res

    def hasNext(self) -> bool:
        return self.arr[0] <= len(self.s) - len(self.arr)   # 结束状态对应的self.arr 为 [len(self.s) - len(self.arr) + 1,
                                                            # len(self.s) - len(self.arr) + 1, ..., len(self.s)]
            


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()
```