### 解题思路
没有数据结构，描述法解题
自定义一个类，
num记录使用次数
value存值
t存最后一次使用时间 用datetime.datetime.now()
### 代码

```python3
import datetime
class V:
    def __init__(self, value, num):
        self.value = value
        self.num = num
        self.t = datetime.datetime.now()
class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.tab = {}
        self.length = 0
    def get(self, key: int) -> int:
        if key in self.tab.keys():
            self.tab[key].num += 1
            self.tab[key].t = datetime.datetime.now()
            return self.tab[key].value
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return
        if key in self.tab.keys():
            self.tab[key].num += 1
            self.tab[key].value = value
            self.tab[key].t = datetime.datetime.now()
        else:
            if self.length < self.capacity:
                self.tab[key] = V(value, 1)
                self.length += 1
            else:
                del_k = 0
                del_num = 10000
                for k,v in self.tab.items():
                    if v.num<del_num:
                        del_num = v.num
                        del_k=k
                    if v.num==del_num:
                        if v.t<self.tab[del_k].t:
                            del_num = v.num
                            del_k=k
                del self.tab[del_k]
                self.tab[key] = V(value, 1)
            


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```