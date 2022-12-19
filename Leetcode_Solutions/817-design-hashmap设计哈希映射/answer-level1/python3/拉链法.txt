### 解题思路
此处撰写解题思路

### 代码

```python3
"""
借鉴hashset加一个计数就行，需要考虑两个问题：
1 hash函数 2 冲突处理
哈希函数采用取余，一般是大质数来降低冲突 这里采用769，冲突处理有 1开放地址法 2 单独链接法（拉链法） 3 双散列法，这里采用2
"""
class MyHashMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.range = 769
        self.bucketarry = [Bucket() for i in range(self.range)]
        
    def hashI(self,x):
      return x % self.range
    def put(self, key: int, value: int) -> None:
        """
        value will always be non-negative.
        count的值是随着输入而改变的，等于put()的value，不是加
        """
        index = self.hashI(key) 
        self.bucketarry[index].insert(key,value)  
      
    def get(self, key: int) -> int:
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        """
        index = self.hashI(key) 
        return self.bucketarry[index].exist(key)    

    def remove(self, key: int) -> None:
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        """
        index = self.hashI(key) 
        self.bucketarry[index].delete(key)    
class Node:
  def __init__(self,val):
    self.val = val
    self.count = 1
    self.next = None
class Bucket:
  def __init__(self):
    self.pre = Node(0)
  def insert(self,val,value):
    if self.exist(val) == -1:#####-1也是非空，只有0等价于非空，所以非空的条件换了
      head = Node(val)
      head.count = value   #####count的值是随着输入而改变的，等于put()的value，不是加
      head.next = self.pre.next
      self.pre.next = head
    else:
      head = self.pre.next
      while head and head.val != val:
        head = head.next
      head.count = value
        
  def exist(self,val):
    head = self.pre.next
    while head:
      if head.val == val:
        return head.count
      head = head.next
    return -1
  def delete(self,val):
    pre = self.pre
    head = pre.next
    while head:
      if head.val == val:
        pre.next = head.next
        return 
      head = head.next 
      pre = pre.next
# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
```