### 解题思路
![微信截图_20200405120649.png](https://pic.leetcode-cn.com/7b01b675eea391395a9c382e15f864abd428fdb0cb2fe1f4006e98dd96332b63-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200405120649.png)

最笨的办法就在LRU的基础上，增加一个times的统计，主要是times和key要绑定在一起操作
### 代码

```python3
class LFUCache:
    def __init__(self, capacity: int):
        self.cap = capacity
        self.key = []  # 存放key
        self.times = []  # 存放key对应着的次数， 每次更新，一定要和key同步
        self.cache = {}

    def get(self, key: int) -> int:
        if key in self.cache:
            index = self.key.index(key)
            self.key.remove(key)
            times = self.times.pop(index)
            self.key.insert(0, key)
            self.times.insert(0, times+1)
            return self.cache[key]
        elif self.cap == 0:
            return -1
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if self.cap == 0:
            return None
        if key in self.cache:
            index = self.key.index(key)
            self.key.remove(key)
            times = self.times.pop(index)
            self.key.insert(0, key)
            self.times.insert(0, times+1)
            self.cache.pop(key)
            self.cache[key] = value
        elif len(self.key) == self.cap:
            self.times.reverse()
            index = self.times.index(min(self.times))
            old_key = self.key.pop(self.cap-1-index)
            self.times.reverse()
            self.times.pop(self.cap-1-index)
            self.cache.pop(old_key)
            self.key.insert(0, key)
            self.times.insert(0, 1)
            self.cache[key] = value
        else:
            self.key.insert(0, key)
            self.times.insert(0, 1)
            self.cache[key] = value

# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```