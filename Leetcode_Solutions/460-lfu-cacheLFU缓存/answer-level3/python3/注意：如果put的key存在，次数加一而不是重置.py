### 解题思路
垃圾题，第一次写了这么久，最后发现提议不清晰，我对着100多行的用例在草纸一步一步推，发现我推的和我代码一样我就知道这题一定有问题我佛了

### 代码

```python3
class LFUCache:

    def __init__(self, capacity: int):
        self.values = [-1]*capacity
        self.keys = [-1]*capacity
        self.freq = [0]*capacity
        self.time = [-1]*capacity
        self.nowTime = 0

    def get(self, key: int) -> int:
        self.nowTime = self.nowTime + 1
        if key not in self.keys: return -1
        index = self.keys.index(key)
        self.freq[index] = self.freq[index] + 1
        self.time[index] = self.nowTime
        return self.values[index]

    def put(self, key: int, value: int) -> None:
        self.nowTime = self.nowTime + 1
        if self.nowTime == 36:
            self.echo()
        if len(self.keys) == 0: return
        if key in self.keys:
            index = self.keys.index(key)
            self.values[index] = value
            self.freq[index] = self.freq[index] + 1
            self.time[index] = self.nowTime
            return
        if 0 in self.freq:
            index = self.freq.index(0)
            self.keys[index] = key
            self.values[index] = value
            self.freq[index] = 1
            self.time[index] = self.nowTime
        else:
            minfreq = min(self.freq)
            minTime = 1e8
            index = -1
            for i in range(len(self.freq)):
                if self.freq[i] == minfreq and self.time[i]<minTime:
                    minTime = self.time[i]
                    index = i
            if self.keys[index] == 6:
                print(self.keys,self.values,self.time,self.freq)
            self.keys[index] = key
            self.values[index] = value
            self.freq[index] = 1
            self.time[index] = self.nowTime    
        
    def echo(self):
        for i in range(10):
            print(self.keys[i], self.values[i], self.time[i], self.freq[i])

```