### 解题思路
第一个字典为限制长度的基本字典，可以实现字典的基本功能。
存放的值带有两个属性(val为传进的参数，fre是使用的次数)，这样当字典容量已满时就可以根据fre来决定删除哪个键值对了。
为了实现O（1）的时间复杂度，以fre为键再建立一个字典。

第二个字典的键是fre，值是一个列表，每当操作第一个字典使得fre发生变化时，把第一个字典的key存放进这个列表中（同时更新之前的fre列表）。
用一个变量m记录已存在的最小fre，在更新fre的同时维护m，当要从第一个字典中删元素时，要删的就是使用最少次数m中的第一个元素。


### 代码

```python3
from collections import defaultdict
class Node:
    def __init__(self,val,fre):
        self.val=val
        self.fre=fre

class LFUCache:

    def __init__(self, capacity: int):
        self.d={}
        self.d2=defaultdict(list)
        self.capacity=capacity
        self.m=0
        
    def increase(self,key):
        self.d2[self.d[key].fre].remove(key)
        if not self.d2[self.d[key].fre] and self.m==self.d[key].fre:
            self.m+=1
        self.d[key].fre+=1
        self.d2[self.d[key].fre].append(key)

    def get(self, key: int) -> int:
        if key in self.d:
            self.increase(key)
            return self.d[key].val
        return -1

    def put(self, key: int, value: int) -> None:
        if not self.capacity:
            return
        if key in self.d:
            self.increase(key)
            self.d[key].val=value
        else:
            if len(self.d)==self.capacity:
                pop_key=self.d2[self.m].pop(0)
                del self.d[pop_key]
            self.d[key]=Node(value,1)
            self.d2[1].append(key)
            self.m=1



        


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```