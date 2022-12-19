Map + 双向链表
- count 相同的 key，放在一个 CountNode 中
- 所有 CountNode 通过双向链表维护，因此可以 O(1) 时间找到 count 最大和最小的 CountNode
- key - CountNode 的 Map：可以保证 O(1) 时间定位 key 所属的 CountNode
- 每个 CountNode 中的所有 key，也通过 Map + 双向链表维护
- 向 CountNode 中添加一个 key，创建一个 KeyNode 对象，放在 keyList 的 keyHead.next，并把相应 key - keyNode 放入Map
- 从 CountNode 中删除一个 key，通过 Map 找到这个 KeyNode 对象，双向链表删除操作，同时删除 Map 中的映射关系

后面暂时不解释了，代码凑乎看。反正是 O(1)，但很慢，因为对象创建销毁操作太频繁了，还可以优化下。

复杂度这东西，并不是说 O(1) 一定比 O(n) 快，只是说 O(1) 复杂度的程序不会随着输入的规模增大，其每次的运行时间变长。但也可能不管输入规模大小，运行效率一直都很差。。至于 O(n) 复杂度表示，运行时间会随着输入规模增大而线性增大。


```
class KeyNode:
    
    def __init__(self, key):
        self.key = key
        self.prev = None
        self.next = None

class KeyList:
    
    def __init__(self):
        self.keyNode = {}
        self.keyHead = KeyNode("")
        self.keyTail = KeyNode("")
        self.keyHead.next = self.keyTail
        self.keyTail.prev = self.keyHead
    
    def isEmpty(self):
        return not self.keyNode
    
    def add(self, key):
        newNode = KeyNode(key)
        newNode.prev, newNode.next = self.keyHead, self.keyHead.next
        self.keyHead.next.prev = newNode
        self.keyHead.next = newNode
        self.keyNode[key] = newNode
    
    def remove(self, key):
        delNode = self.keyNode[key]
        delNode.prev.next, delNode.next.prev = delNode.next, delNode.prev
        del self.keyNode[key]
    
    
class CountNode:
    
    def __init__(self, count):
        self.count = count
        self.keyList = KeyList()
        self.prev = None
        self.next = None
    
    def isEmpty(self):
        return self.keyList.isEmpty()
    
    def add(self, key):
        self.keyList.add(key)
    
    def remove(self, key):
        self.keyList.remove(key)
    
    def getKey(self):
        return self.keyList.keyHead.next.key

        

class CountList:
    
    def __init__(self):
        self.keyCountNode = {}
        self.countHead = CountNode(-1)
        self.countTail = CountNode(-1)
        self.countHead.next = self.countTail
        self.countTail.prev = self.countHead
    
    def isEmpty(self):
        return not self.keyCountNode
    
    def add(self, key):
        if key not in self.keyCountNode:
            if self.countHead.next.count == 1:
                self.countHead.next.add(key)
            else:
                oneCount = CountNode(1)
                oneCount.add(key)
                oneCount.prev, oneCount.next = self.countHead, self.countHead.next
                self.countHead.next.prev, self.countHead.next = oneCount, oneCount
            self.keyCountNode[key] = self.countHead.next
        else:
            countNode = self.keyCountNode[key]
            moreCount = countNode.count + 1
            if countNode.next.count == moreCount:
                countNode.next.add(key)
                self.keyCountNode[key] = countNode.next
            else:
                newNode = CountNode(moreCount)
                newNode.add(key)
                newNode.prev, newNode.next = countNode, countNode.next
                countNode.next.prev, countNode.next = newNode, newNode
                self.keyCountNode[key] = newNode
            
            countNode.remove(key)
            if countNode.isEmpty():
                countNode.prev.next, countNode.next.prev = countNode.next, countNode.prev
        
    
    def remove(self, key):
        countNode = self.keyCountNode[key]
        lessCount = countNode.count - 1
        if countNode.prev.count == lessCount:
            countNode.prev.add(key)
            self.keyCountNode[key] = countNode.prev
        elif lessCount != 0:
            newNode = CountNode(lessCount)
            newNode.add(key)
            newNode.prev, newNode.next = countNode.prev, countNode
            countNode.prev.next, countNode.prev = newNode, newNode
            self.keyCountNode[key] = newNode
        else:
            del self.keyCountNode[key]
        
        countNode.remove(key)
        if countNode.isEmpty():
            countNode.prev.next, countNode.next.prev = countNode.next, countNode.prev
    

class AllOne:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.countList = CountList()
        

    def inc(self, key: str) -> None:
        """
        Inserts a new key <Key> with value 1. Or increments an existing key by 1.
        """
        self.countList.add(key)

    def dec(self, key: str) -> None:
        """
        Decrements an existing key by 1. If Key's value is 1, remove it from the data structure.
        """
        if key not in self.countList.keyCountNode:
            return
        self.countList.remove(key)


    def getMaxKey(self) -> str:
        """
        Returns one of the keys with maximal value.
        """
        if self.countList.isEmpty():
            return ""
        return self.countList.countTail.prev.getKey()

    def getMinKey(self) -> str:
        """
        Returns one of the keys with Minimal value.
        """
        if self.countList.isEmpty():
            return ""
        return self.countList.countHead.next.getKey()

```
