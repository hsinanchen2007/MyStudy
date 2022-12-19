不加入链表，实现简单，用字典保存 [value,time]，再用一个list保存key的次数。
在删除或者更新self.count时复杂度为O(capacity)

```
class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}
        self.count = [[]]

    def refresh_count(self,time,key):
        self.count[time].remove(key)
        if len(self.count)==time+1:
            self.count.append([key])
        else:
            self.count[time+1].append(key)

    def get(self, key: int) -> int:
        if self.capacity==0:
            return -1
        cache = self.cache
        if key in cache:
            time = cache[key][1]
            self.refresh_count(time,key)
            self.cache[key][1] = time+1
            return cache[key][0]
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if self.capacity==0:
            return
        if key in self.cache:
            time = self.cache[key][1]
            self.refresh_count(time,key)
            self.cache[key] =[value,time+1]
        else:
            if len(self.cache)==self.capacity:
                del_key = -1
                for l in self.count:
                    if len(l)>0:
                        del_key =l.pop(0)
                        break
                self.cache.pop(del_key)

            self.cache[key]=[value,0]
            self.count[0].append(key)
```
