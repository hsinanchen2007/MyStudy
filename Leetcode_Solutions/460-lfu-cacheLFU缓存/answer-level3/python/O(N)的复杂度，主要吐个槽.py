### 解题思路
吐个槽，我记得LRU是丢最远的没用过的，然后题目强调丢最近的。。实际上试了一下还是丢最远的那个。。

实现上插删都是O(n),确实不会写O(1)的。。

### 代码

```python3
class LFUCache:
    from collections import defaultdict
    def __init__(self, capacity: int):
        self.size = capacity
        self.lfu = defaultdict(int)
        self.freq = defaultdict(int)
        self.order = []

    def get(self, key: int) -> int:
        if key in self.lfu.keys():
            self.order.remove(key)
            self.order.append(key)
            self.freq[key] += 1
            return self.lfu[key]
        return -1
        

    def put(self, key: int, value: int) -> None:

        if key in self.lfu.keys():
            self.order.remove(key)
        self.order.append(key)
        self.lfu[key] = value
        self.freq[key] += 1
        if len(self.order) > self.size:
            toRemove = self.order[0]
            Freq = self.freq[self.order[0]]
            for item in self.order[1:-1]:
                if Freq > self.freq[item]:
                    toRemove = item
                    Freq = self.freq[item]
            self.order.remove(toRemove)
            self.freq[toRemove] = 0
            del self.lfu[toRemove]
        
        


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```