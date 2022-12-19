```python3
class LFUCache:

    def __init__(self, capacity: int):
        self.adict = dict()
        self.capacity = capacity
        self.cache = []

    def get(self, key: int) -> int:
        if key in self.adict.keys():
            node = self.adict.get(key)

            # 需要更新一下cache
            self.cache.remove(node) # 删除cache中的原node
            node.cnt += 1 # 使用频率增加 1
            self.insertNode(node)
            return node.value
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return

        if key not in self.adict.keys():
            if len(self.cache) == self.capacity: # cache容量已经满了
                head = self.cache.pop(0) # cache队首出队
                self.adict.pop(head.key) # adict中的head元素删除

            node = Node(0, key, value) # 为当前<key, value>创建节点
            self.adict[key] = node # 将新的node增添到dict中

            self.insertNode(node) # 将新的node插入到cache中

        else: #和上面的get函数类似
            node = self.adict.get(key)
            self.adict.pop(key)
            self.cache.remove(node)
            node.value = value #更新node值
            node.cnt += 1
            self.adict[key] = node
            self.insertNode(node)

    def insertNode(self, node): # 将node节点插入到cache中的合适位置
        for i in range(len(self.cache)):
            if self.cache[i].cnt > node.cnt:
                self.cache.insert(i,node)
                break
        else:
            self.cache.append(node)        

class Node:
    def __init__(self, cnt, key, value):
        self.cnt = cnt
        self.key = key
        self.value = value
```
