### 解题思路
python 双字典

key到value+freq的映射
self.key_dict = {}  # key:[value, freq]

freq映射到所有相应freq的key的双向队列，新到旧排列，更新freq时从左侧插入，容量满需要删除时，从右侧pop
self.freq_dict = defaultdict(deque) # freq: list[key] new -> old
### 代码

```python3
from collections import defaultdict,deque
class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.num = 0
        self.key_dict = {}  # key:[value, freq]
        self.freq_dict = defaultdict(deque) # freq: list(key) new -> old
        self.min_freq = 1
        pass

    def get(self, key: int) -> int:
        if key in self.key_dict:
            res = self.key_dict[key][0]
            freq = self.key_dict[key][1]
        else:
            return -1
        self.freq_dict[freq].remove(key)
        # 更新使用频率，从原freq移到freq+1，如果是freq最后一个并且刚好是min_freq,则更新min_freq
        if len(self.freq_dict[freq]) == 0:
            self.freq_dict.pop(freq)
            if freq == self.min_freq:
                self.min_freq += 1
            
        self.freq_dict[freq+1].appendleft(key)
        self.key_dict[key][1]= freq+1
        return res

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return
        # 如果put已存在的值，相当于get加更新value
        if key in self.key_dict:
            self.get(key)
            self.key_dict[key][0] = value
        else:
            # 容量没满，2个dict插入key，value，freq为1，数量加1，min_freq置为1
            if self.num < self.capacity:
                self.key_dict[key] = [value,1]
                self.freq_dict[1].appendleft(key)
                self.num += 1
                self.min_freq = 1
            # 容量满了，删除min_freq对应的队列最老的值，再插入新值
            else:
                # print("self.min_freq,key,freq_dict",self.min_freq,key,self.freq_dict)
                del_key = self.freq_dict[self.min_freq].pop()
                self.key_dict.pop(del_key)

                self.key_dict[key] = [value, 1]
                self.freq_dict[1].appendleft(key)

                if len(self.freq_dict[self.min_freq]) == 0:
                    self.freq_dict.pop(self.min_freq)

                self.min_freq = 1


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```