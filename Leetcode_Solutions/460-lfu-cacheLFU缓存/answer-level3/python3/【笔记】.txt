### 解题思路
简单思路，见注释

注意！！put()操作若key已存在，赋新value值，**使用频次freq+1而不是重置为1**，更新使用时间time。
原以为应该将freq重置，搞得一直解答错误。。。

### 代码

```python
class LFUCache(object):

    def __init__(self, capacity):
        self.capacity = capacity
        self.time = 0 # 时间计数，每次调用get()则+1
        self.dic = {} # key:[value, freq, time]
                      # 键:[值，使用频次，最近使用时间]
        

    def get(self, key):
        if self.capacity == 0:
            return -1
        if key not in self.dic:
            return -1
        self.time += 1
        self.dic[key][1] += 1
        self.dic[key][2] = self.time
        return self.dic[key][0]
        

    def put(self, key, value):
        if self.capacity == 0:
            return None
        self.time += 1
        # key已存在
        if key in self.dic: 
            self.dic[key][0] = value
            self.dic[key][1] += 1
            self.dic[key][2] = self.time
            return None
        # key不存在
        if len(self.dic) < self.capacity: # 缓存未满
            self.dic[key] = [value, 1, self.time]
        else: # 缓存已满
            least_freq = min(self.dic.values(), key=lambda x:x[1])[1]
            # 找到最小使用频次,注意min()返回的是[val,freq,time]
            keys = [i for i,j in self.dic.items() if j[1] == least_freq] # 找到对应键
            if len(keys) == 1: # 最不常使用的只有一个
                del self.dic[keys[0]]
            else: # 有多个最不常使用的，则删除使用时间最早的
                least_key = keys[0]
                least_time = self.dic[least_key][2]
                for i in keys:
                    if self.dic[i][2] < least_time:
                        least_key = i
                        least_time = self.dic[least_key][2]
                del self.dic[least_key]
            self.dic[key] = [value, 1, self.time]
        


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```