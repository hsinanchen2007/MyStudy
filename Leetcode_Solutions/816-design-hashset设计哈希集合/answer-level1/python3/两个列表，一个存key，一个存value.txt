### 解题思路
脑子第一反应就是同存同取，列表分开存放就好了，没有大神们的链表、二叉树的各种思路，通过没问题，但是效率相对较低，大概这就是小白吧

### 代码

```python3
class MyHashSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.keys = []
        self.values = []
        

    def add(self, key: int) -> None:
        if key in self.keys:
            self.values[self.keys.index(key)] += 1
        else:
            self.keys.append(key)
            self.values.append(1)
        

    def remove(self, key: int) -> None:
        if key in self.keys:
            self.values.pop(self.keys.index(key))
            self.keys.pop(self.keys.index(key))

    def contains(self, key: int) -> bool:
        """
        Returns true if this set contains the specified element
        """
        return key in self.keys


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
```