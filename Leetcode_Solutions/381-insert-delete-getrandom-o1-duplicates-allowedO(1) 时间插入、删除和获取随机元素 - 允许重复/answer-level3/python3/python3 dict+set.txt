### 解题思路
其实这道题的思路和不允许重复的是一样的，只是把字典中存储的单个索引换成了set（或者数组）
不清楚 set 的 pop方法是不是 o（1）的，如果不是，可以换成 list

### 代码

```python3
import random
class RandomizedCollection:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.data = []
        self.dict = {}

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
        """
        if val not in self.dict:
            self.dict[val] = {len(self.data)}
        else:
            self.dict[val].add(len(self.data))
        self.data.append(val)
        if len(self.dict[val]) == 1:
            return True
        return False

    def remove(self, val: int) -> bool:
        """
        Removes a value from the collection. Returns true if the collection contained the specified element.
        """
        if val in self.dict:
            idx = self.dict[val].pop()
            # print(idx)
            if idx != len(self.data)-1:
                last = self.data[-1]
                self.data[idx] = last
                self.dict[last].remove(len(self.data)-1)
                self.dict[last].add(idx)
                self.data.pop()
            else:
                self.data.pop()

            if len(self.dict[val]) == 0:
                self.dict.pop(val)
            
            return True
        return False

    def getRandom(self) -> int:
        """
        Get a random element from the collection.
        """
        return self.data[random.randint(0, len(self.data)-1)]


# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# print(obj.insert(1))
# print(obj.insert(1))
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
```