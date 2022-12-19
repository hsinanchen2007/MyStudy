### 解题思路

两个map：
    一个用于搜索：存key、val、cnt
    一个用于调度：双链表，改变节点优先级

### 代码

```python
class keyDictNode:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.pre = None
        self.cnt = 1
        self.next = None
class KeyDict:
    def __init__(self):
        self.tab = {}
    def get(self, key):
        if key  in self.tab: return self.tab[key] 
        return None 

    def put(self, key, value):
        if key in self.tab:
            self.tab[key] = value
            return self.tab[key]
        else:
            node = keyDictNode(key, value)
            self.tab[key] = node
            return node
    def delete(self, key):
        self.tab.pop(key, '404')

class FreDictNode:
    def __init__(self, node):
        node.pre = node.next = None
        self.head = node
        self.tail = node
class FreDict:
    def __init__(self):
        self.minFre = 1
        self.tab = {}
    # 删除节点【四种情况：该层级消失， 删掉首节点、删掉尾节点、删掉中间节点】
    def delete(self, node):
        dnode = self.tab[node.cnt]
        if node == dnode.head and node == dnode.tail:
            self.tab.pop(node.cnt)
            if self.minFre >= node.cnt :
                self.minFre+=1
                while self.tab and self.minFre not in self.tab:
                    self.minFre+=1
        elif node == dnode.head:
            dnode.head = node.next
            node.next.pre = None
        elif node == dnode.tail:
            dnode.tail = node.pre
            node.pre.next = None
        else:
            node.next.pre = node.pre
            node.pre.next = node.next
    # 放入节点【放入指定层级队首】
    def put(self, node):
        self.minFre = min(self.minFre, node.cnt)
        if node.cnt in self.tab:
            dnode = self.tab[node.cnt]

            node.next = dnode.head
            node.next.pre = node
            
            node.pre = None
            dnode.head = node
        else:       
            self.tab[node.cnt] = FreDictNode(node)
    # 删除尾节点【最小层级队尾】
    def expire(self):
        node = self.tab[self.minFre].tail
        self.delete(node)
        return node

class LFUCache(object):
    def __init__(self, capacity):
        self.keyDict = KeyDict()
        self.freDict = FreDict()
        self.capacity = capacity
        self.size = 0

    def get(self, key):
        node = self.keyDict.get(key)
        if not node: return -1
        # 双链表中，删除一个节点，然后插入一个节点
        self.freDict.delete(node)
        node.cnt+=1
        self.freDict.put(node)

        return node.val
        

    def put(self, key, value):
        if self.capacity==0: return

        node = self.keyDict.get(key)
        # 按照get处理
        if node:
            node.val = value
            self.get(key)
        else:
            # 删除两个hash表中尾节点
            if self.size==self.capacity:
                node = self.freDict.expire()
                self.keyDict.delete(node.key)
            else:
                self.size += 1
            # 新节点插入两表
            node = self.keyDict.put(key, value) 
            self.freDict.put(node)            
```