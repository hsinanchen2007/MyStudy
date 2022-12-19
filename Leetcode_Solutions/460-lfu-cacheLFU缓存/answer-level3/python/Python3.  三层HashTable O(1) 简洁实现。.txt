### 解题思路
![Capture.PNG](https://pic.leetcode-cn.com/eb2fc6bd91851c529ff56c34b07294645b3d9b0f98433ac703f63dd5c9408496-Capture.PNG)
     
一点猜测，有人知道还请留言      
不清楚OrderedDict的实现细节， 各种操作的时间复杂度，估计是O(1)，不管是删除特定值，还是两端的值
综合来看我觉得，reference 相同的情况下 随机删除一个的性能应该比这个按FIFO的顺序替换要好。简单的可以直接用一个哈希表，而且随机的准确率不会比FIFO差多少
每隔一段时间再减少一定数量的引用数



### 代码

```python3
from collections import OrderedDict
from collections import defaultdict

class LFUCache:
    def __init__(self, capacity: int): 
        self.index = defaultdict(OrderedDict)  # (refer: OrderedDict(key, value))
        self.data = {} # (key: refer)  (#refer的值需要一个能快速查找删除，插入，并保持插入顺序的数据结构)O(1)我只能想到Hash了。
        self.minR = 0                
        self.lenth = 0
        self.limit = capacity 
    
    def get(self, key: int) -> int:
        try:
            refer = self.data[key]
            self.data[key] = refer+1 # 更新引用表
            value = self.index[refer].pop(key)
            self.index[refer+1][key] = value #更新数据表 
            if not self.index[refer] and self.minR == refer: # 移动键对minR的影响
                self.minR += 1
            #print(self.data, value, self.minR)
            return value
        except KeyError:
            #print(self.data, -1)
            return -1
                
    
    def put(self, key: int, value: int) -> None:
        if key in self.data: #已存在的Key
            refer = self.data[key]
            self.data[key] = refer+1 # 更新引用表          
            self.index[refer+1][key] = value
            del self.index[refer][key] # 更新数据表
            if not self.index[refer] and self.minR == refer:
                self.minR += 1                                      # 更新minR         
        else:
            if self.lenth >= self.limit: # 新key先检查长度
                try:
                    Dkey, _ = self.index[self.minR].popitem(last = False) #默认是LIFO 害的我弄了半个小时
                    self.data.pop(Dkey)
                    self.lenth -= 1
                except KeyError: #变态的测试缓存大小竟然为0
                    return -1    
            self.minR = 1
            self.data[key] = 1 #更新引用表
            self.index[1][key] = value #更新数据表                              
            self.lenth += 1
        #print(self.data, 'null') 
        
        
        
# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```