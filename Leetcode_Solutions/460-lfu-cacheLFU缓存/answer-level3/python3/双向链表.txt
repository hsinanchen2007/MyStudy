### 解题思路
此处撰写解题思路

### 代码

```python3
class Node:
    def __init__(self, key, val):
        self.pre = None
        self.nex = None
        self.freq = 0
        self.val = val
        self.key = key
    def insert(self, new):
        new.pre = self
        new.nex = self.nex
        self.nex.pre = new
        self.nex = new

# 创建循环双向链表
def linked_list():
    head = Node(0, 0)
    tail = Node(0, 0)
    head.nex = tail
    tail.pre = head
    return (head, tail)

class LFUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.minFreq = 0
        self.size = 0
        # 频率字典，每个item里存储某个频率以及这个频率对应的一个链表，这个链表的各个节点存储key,value
        self.freqMap = collections.defaultdict(linked_list)
        # keyMap存储频率和对应的节点，节点就是key-value链表节点
        self.keyMap = {}

    def delete(self, node):
        # 要删除一个节点，需要先找到它的前驱
        if node.pre:
            node.pre.nex = node.nex
            node.nex.pre = node.pre
            # 删除节点之后要判断下这个链表是否为空，如果为空，这删除这个链表
            if node.pre is self.freqMap[node.freq][0] and node.nex is self.freqMap[node.freq][-1]:
                self.freqMap.pop(node.freq)
        return node.key

    def increase(self, node):
        node.freq += 1
        self.delete(node)
        self.freqMap[node.freq][-1].pre.insert(node)
        # 最开始freq是0，此时将节点插入freq为1的链表中，最小频率更新为1；
        # 若原链表频率不为0且是最小频率，节点插入新链表后，需要判断原链表是否为空，若为空，则最小频率为新链表频率，若不为空，则最小频率还是原链表频率
        if node.freq == 1:
            self.minFreq = 1
        elif self.minFreq == node.freq - 1:
            head, tail = self.freqMap[node.freq - 1]
            if head.nex == tail:
                self.minFreq = node.freq

    def get(self, key: int) -> int:
        if key in self.keyMap:
            # 当前节点get之后，频率增加，所以它在freqMap的顺序要变,把它加入到更高频率的链表中
            self.increase(self.keyMap[key])
            return self.keyMap[key].val
        return -1

    def put(self, key: int, value: int) -> None:
        if self.capacity != 0:
            if key in self.keyMap:
                node = self.keyMap[key]
                node.val = value
            else:
                node = Node(key, value)
                self.keyMap[key] = node
                self.size += 1
            if self.size > self.capacity:
                self.size -= 1
                d = self.delete(self.freqMap[self.minFreq][0].nex)
                self.keyMap.pop(d)
            self.increase(node)




        


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

```