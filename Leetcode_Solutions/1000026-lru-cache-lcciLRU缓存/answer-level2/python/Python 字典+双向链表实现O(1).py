```py
class node:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.bp = None
        self.np = None

class LRUCache:

    def __init__(self, capacity: int):
        self.maxNum = capacity
        self.head = None
        self.tail = None
        self.key2node = {}

    def get(self, key: int) -> int:
        if key not in self.key2node: return -1
        n = self.key2node[key] # 将该节点作为head
        if self.tail == n and self.tail.bp: self.tail = self.tail.bp
        if self.head != n:
            # 将该节点摘下
            if n.bp: n.bp.np = n.np
            if n.np: n.np.bp = n.bp
            # 将该节点插到当前head节点前并更新head
            self.head.bp = n
            n.np = self.head
            n.bp = None
            self.head = n
        return self.head.val


    def put(self, key: int, value: int) -> None:
        if key in self.key2node: # 如果当前key存在则更新value并做一次get
            self.key2node[key].val = value
            self.get(key)
        else:
            if not self.maxNum: # 空间已满则从字典删除key并更新tail和容量
                self.key2node.pop(self.tail.key)
                self.tail = self.tail.bp
                if self.tail: self.tail.np = None
                self.maxNum += 1
            # 创建新节点插入到当前head节点前并更新head
            n = node(key, value)
            self.key2node[key] = n
            if not self.tail: self.tail = n # 初始化tail
            if self.head:
                n.np = self.head
                self.head.bp = n
            self.head = n
            self.maxNum -= 1
```