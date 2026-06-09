### 解题思路
如代码

### 代码

```python3
class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.key_list = {}
        self.time = 0
        

    def get(self, key: int) -> int:
        self.time += 1
        if key in self.key_list:
            '''
            for i in self.key_list:
                if i != key:
                    self.key_list[i][1] -= 1'''
            self.key_list[key][0] += 1
            self.key_list[key][1] = self.time 
            #print(key,self.key_list[key])
            return self.key_list[key][2]
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        self.time += 1
        '''
        for i in self.key_list:
            if i != key:
                self.key_list[i][1] -= 1'''
        if self.capacity==0:
            return 
        if (key not in self.key_list) and len(self.key_list)<self.capacity:
            self.key_list[key] = [0, self.time, value]
        elif (key in self.key_list) and len(self.key_list)<=self.capacity:
            self.key_list[key][0] += 1
            self.key_list[key][1] = self.time
            self.key_list[key][2] = value
            #print(key,self.key_list[key])
        elif (key not in self.key_list) and len(self.key_list)==self.capacity:
            seq = sorted(self.key_list, key = lambda key: self.key_list[key])
            #print(seq)
            #print(self.key_list[seq[0]])
            #print(self.key_list[seq[1]])
            if len(seq)>0:
                del self.key_list[seq[0]]
            self.key_list[key] = [0, self.time, value]
        else:
            return "Error"
        



# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```