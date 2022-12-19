嗯，照着liweiwei大佬的图，自己写出来了。先用给的测试用例运行了几次，发现还是有不少错误的。但终究写出来了，还是有点小成就感的哈哈。

```
class ListNode:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.freq = 1
        self.pre = None
        self.nxt = None


class MuteList:    # 双向列表
    def __init__(self):
        self.dummyHead = ListNode(-1, -1)
        self.dummyTail = ListNode(-1, -1)
        # 初始时为空，辅助头结点和辅助尾结点指向彼此
        self.dummyHead.pre, self.dummyHead.nxt = self.dummyTail, self.dummyTail
        self.dummyTail.nxt, self.dummyTail.pre = self.dummyHead, self.dummyHead


class LFUCache:
    def __init__(self, capacity: int):
        self.cache = {}
        self.freqMap = {}
        self.cap = capacity
        self.maxFreq = 1
        pass

    def remove(self, node):    # 从self.freqMap里删除
        node.pre.nxt, node.nxt.pre = node.nxt, node.pre
        node.pre, node.nxt = None, None
        lst = self.freqMap[node.freq]
        if lst.dummyHead.nxt == lst.dummyTail:
            self.freqMap.pop(node.freq)

    def insert(self, node):    # 也是向self.freqMap里插入
        if node.freq not in self.freqMap:
            self.freqMap.update({node.freq: MuteList()})
        lst = self.freqMap[node.freq]
        lst.dummyHead.nxt.pre = node
        node.nxt = lst.dummyHead.nxt
        lst.dummyHead.nxt = node
        node.pre = lst.dummyHead
        self.maxFreq = max(self.maxFreq, node.freq)

    def get(self, key: int) -> int:
        if (self.cap <= 0) or (key not in self.cache):
            return -1
        node = self.cache[key]
        # 从当前双向链表中删除结点，若双向链表的size为0则删除这个链表
        self.remove(node)
        # 将结点访问频次增加一，并插入对应的双向链表的头部
        node.freq += 1
        self.insert(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        if self.cap <= 0:
            return
        if key in self.cache:
            node = self.cache[key]
            node.val = value    # 更新值
            self.remove(node)
            node.freq += 1
            self.insert(node)
        else:
            if len(self.cache) == self.cap:    # cache满了就要淘汰
                for i in range(1, self.maxFreq + 1):
                    if i in self.freqMap:
                        break
                lfu = self.freqMap[i].dummyTail.pre    # 因为把最新访问过的插入头部，所以尾部就是最久未访问的
                self.remove(lfu)
                self.cache.pop(lfu.key)    # key被删除了，别忘了更新cache字典
            # 生成新结点，并将新结点插入freqMap[1]
            node = ListNode(key, value)
            self.insert(node)
            self.cache.update({key: node}) # 这里也别忘了
```
