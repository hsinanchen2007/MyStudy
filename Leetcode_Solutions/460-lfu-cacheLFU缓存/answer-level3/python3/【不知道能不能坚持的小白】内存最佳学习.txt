### 解题思路
学习结果里面的内存最佳方法。
这里的思路跟时间最佳是一模一样。就不多废话了。https://leetcode-cn.com/problems/lfu-cache/solution/bu-zhi-dao-neng-bu-neng-jian-chi-de-xiao-bai-shi-4/
唯一一点是在实现上，其实是不需要用OrderedDict的，构建一个栈，按压栈的顺序，pop(0)就是最早进栈的那个。
扫了一眼看到还有用双向链方法的，以后有机会再看。

### 代码

```python3
class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}
        self.freq_key = {}

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1

        # 找出当前key的频率并加1
        for freq in self.freq_key:
            if key in self.freq_key[freq]:
                self.freq_key[freq].remove(key)
                if not self.freq_key[freq]:
                    self.freq_key.pop(freq)
                # 关键在这里，setdefault构建一个栈然后压栈
                self.freq_key.setdefault(freq + 1, []).append(key)
                break

        return self.cache.get(key)

    def put(self, key: int, value: int) -> None:
        if self.capacity <= 0:
            return
        if key not in self.cache:
            if len(self.cache) == self.capacity:
                # 弹出频率最小的第一个元素，并移除
                pop_key = self.freq_key[min(self.freq_key)].pop(0)
                self.cache.pop(pop_key)

            self.cache[key] = value
            self.freq_key.setdefault(1, []).append(key)
        else:
            self.cache[key] = value
            self.get(key)

# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```