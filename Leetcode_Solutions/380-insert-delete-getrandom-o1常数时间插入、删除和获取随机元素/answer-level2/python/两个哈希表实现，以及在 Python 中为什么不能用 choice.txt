### 思路

题目要求时间复杂度为 `O(1)`，所以需要使用两个哈希表进行数据的存储：

1. 哈希表一：元素值作为 `key`，元素下标作为 `value`
2. 哈希表二：元素下标作为 `key`，元素值作为 `value`。该表的存在是为了 `getRandom` 时达到时间复杂度 `O(1)`

具体操作方式如下：

1. `insert` 操作：判断 `val` 值是否存在，不存在则在两个哈希标中加入该值；
2. `remove` 操作：取出将要移除 `val` 的下标 `index`，将当前所有元素的最大下标改为 `index` 值，然后 `remove` 元素 `val`

### 为什么不能用 choice？

看到有答案用了 `random.choice`，在这里贴一下 Python 中 `random.choice` 的实现方式，事件复杂度不可能是 `O(1)`，一看便知了。

```
def choice(self, seq):
        """Choose a random element from a non-empty sequence."""
        try:
            i = self._randbelow(len(seq))
        except ValueError:
            raise IndexError('Cannot choose from an empty sequence') from None
        return seq[i]

# choice 中调用的 _randbelow 方法
def _randbelow(self, n, int=int, maxsize=1<<BPF, type=type,
                   Method=_MethodType, BuiltinMethod=_BuiltinMethodType):
        "Return a random int in the range [0,n).  Raises ValueError if n==0."

        random = self.random
        getrandbits = self.getrandbits
        # Only call self.getrandbits if the original random() builtin method
        # has not been overridden or if a new getrandbits() was supplied.
        if type(random) is BuiltinMethod or type(getrandbits) is Method:
            k = n.bit_length()  # don't use (n-1) here because n can be 1
            r = getrandbits(k)          # 0 <= r < 2**k
            while r >= n:
                r = getrandbits(k)
            return r
        # There's an overridden random() method but no new getrandbits() method,
        # so we can only use random() from here.
        if n >= maxsize:
            _warn("Underlying random() generator does not supply \n"
                "enough bits to choose from a population range this large.\n"
                "To remove the range limitation, add a getrandbits() method.")
            return int(random() * n)
        if n == 0:
            raise ValueError("Boundary cannot be zero")
        rem = maxsize % n
        limit = (maxsize - rem) / maxsize   # int(limit * maxsize) % n == 0
        r = random()
        while r >= limit:
            r = random()
        return int(r*maxsize) % n
```

### 具体实现

```python
from random import randint

class RandomizedSet(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.key_index_map = dict()
        self.index_key_map = dict()
        self.index = 0
        

    def insert(self, val):
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        if val not in self.key_index_map:
            self.index += 1
            self.key_index_map[val] = self.index
            self.index_key_map[self.index] = val
            return True
        else:
            return False
        

    def remove(self, val):
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        :type val: int
        :rtype: bool
        """
        if val not in self.key_index_map:
            return False
        else:
            remove_index = self.key_index_map[val]
            # 替换
            self.index_key_map[remove_index] = self.index_key_map[self.index]
            self.key_index_map[self.index_key_map[self.index]] = remove_index
            # 弹出 remove 元素
            self.key_index_map.pop(val)
            self.index_key_map.pop(self.index)
            self.index -= 1
            return True

    def getRandom(self):
        """
        Get a random element from the set.
        :rtype: int
        """
        return self.index_key_map[randint(1, self.index)]
        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
```