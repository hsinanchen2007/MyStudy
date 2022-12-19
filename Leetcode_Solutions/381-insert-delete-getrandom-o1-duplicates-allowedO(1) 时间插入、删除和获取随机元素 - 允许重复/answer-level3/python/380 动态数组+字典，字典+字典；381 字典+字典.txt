考察数据结构设计

[380. 常数时间插入、删除和获取随机元素](https://leetcode-cn.com/problems/insert-delete-getrandom-o1/)

动态数组+字典

动态数组存储值，执行`append()`和`pop()`，移至最数组末尾O(1)处理

字典存储值及其索引，维护值和索引的动态变化

时间复杂度O(1)，空间复杂度O(N)，Python完整代码如下所示。
```python3
import random
class RandomizedSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.lst = []
        self.idx = {}

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        """
        if val not in self.idx:
            self.idx[val] = len(self.lst)
            self.lst.append(val)
            return True
        return False

    def remove(self, val: int) -> bool:
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        """
        if val in self.idx:
            index = self.idx[val]  # remove index
            fill = self.lst[-1]  # last value
            self.lst[index] = fill
            self.idx[fill] = index
            del self.idx[val]
            self.lst.pop()
            return True
        return False


    def getRandom(self) -> int:
        """
        Get a random element from the set.
        """
        return random.choice(self.lst)
```

<br/>
字典+字典

一个存储索引及其值，，另一个字典存储值及其索引，共同维护值和索引的动态变化

时间复杂度O(1)，空间复杂度O(N)，老代码了，变量名未做修改，运行比上述代码稍快。
```python3
import random
class RandomizedSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.key_num_map = {}
        self.num_key_map = {}
        self.count = 0

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        """
        key = val
        if key not in self.key_num_map:
            self.key_num_map[key] = self.count
            self.num_key_map[self.count] = key
            self.count += 1
            return True
        return False

    def remove(self, val: int) -> bool:
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        """
        key = val
        if key in self.key_num_map:
            self.count -= 1
            num = self.key_num_map[key]  # number the key mapping in key_num_map
            fill = self.num_key_map[self.count]  # last key in num_key_map
            self.key_num_map[fill] = num
            self.num_key_map[num] = fill
            del self.num_key_map[self.count]
            del self.key_num_map[key]
            return True
        return False


    def getRandom(self) -> int:
        """
        Get a random element from the set.
        """
        return self.num_key_map[random.randrange(0, self.count)]
```



<br/>
[381. O(1) 时间插入、删除和获取随机元素 - 允许重复](https://leetcode-cn.com/problems/insert-delete-getrandom-o1-duplicates-allowed/)

动态数组+字典，

动态数组依旧存储值，执行`append()`和`pop()`，移至最数组末尾O(1)处理

字典存储值及其索引集合，维护值和索引集合的动态变化

参照[380. 常数时间插入、删除和获取随机元素](https://leetcode-cn.com/problems/insert-delete-getrandom-o1/) 动态数组+字典版代码进阶，此时字典由存储值及索引变成值及其索引集合

```python3
import random
class RandomizedCollection:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.lst = []
        self.idx = {}

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
        """
        if val not in self.idx:
            self.idx[val] = set()
        self.idx[val].add(len(self.lst))
        self.lst.append(val)
        return len(self.idx[val]) == 1

    def remove(self, val: int) -> bool:
        """
        Removes a value from the collection. Returns true if the collection contained the specified element.
        """
        if val not in self.idx or len(self.idx[val]) == 0:
            return False
        index = self.idx[val].pop()
        last = self.lst[-1]
        self.lst[index] = last
        self.idx[last].add(index)
        self.idx[last].discard(len(self.lst) - 1)
        self.lst.pop()
        return True

    def getRandom(self) -> int:
        """
        Get a random element from the collection.
        """
        return random.choice(self.lst)
```