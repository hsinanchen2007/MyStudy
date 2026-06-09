### 解题思路
缓存一个计数池，每次操作从计数池中随机抽取元素，当计数池中某元素少于等于0时，剔除该元素，当所有元素都少于等于0则重置该计数池。

### 代码

```python3
class Solution:

    def __init__(self, w: List[int]):
        total_val = sum(w)
        self.w = list(map(lambda x: int(math.ceil(x/total_val*100)), w))
        self.pool = None
        self.keys = None
        self._init_keys()
    
    def _init_keys(self):
        self.keys = []
        self.pool = self.w[:]
        for index in range(len(self.w)):
            if self.w[index] > 0:
                self.keys.append(index)

    def pickIndex(self) -> int:
        if len(self.keys) == 0:
            self._init_keys()
        selected = random.randint(0, len(self.keys)-1)
        res = self.keys[selected]
        self.pool[res] -= 1
        if self.pool[res] <= 0:
            self.keys.pop(selected)
        return res




# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
```