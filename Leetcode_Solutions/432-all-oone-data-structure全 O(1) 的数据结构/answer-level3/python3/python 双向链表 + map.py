## 思路:

先用投机过啊! 哈哈

```python
class AllOne:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.lookup = {}
        

    def inc(self, key: str) -> None:
        """
        Inserts a new key <Key> with value 1. Or increments an existing key by 1.
        """
        self.lookup.setdefault(key, 0)
        self.lookup[key] += 1
        

    def dec(self, key: str) -> None:
        """
        Decrements an existing key by 1. If Key's value is 1, remove it from the data structure.
        """
        if key in self.lookup:
            if self.lookup[key] == 1:
                self.lookup.pop(key)
            else:
                self.lookup[key] -= 1

    def getMaxKey(self) -> str:
        """
        Returns one of the keys with maximal value.
        """
        return max(self.lookup.items(), key=lambda x: x[1], default=[""])[0]
        

    def getMinKey(self) -> str:
        """
        Returns one of the keys with Minimal value.
        """
        return min(self.lookup.items(), key=lambda x: x[1], default=[""])[0]
```

当然，还是那句话：**过不是我们的目的，目的是锻炼自己代码能力。**

题目中说以 $O(1)$的时间，我们可以采用双向链表，如下图所示

![image-20200304162915545.png](https://pic.leetcode-cn.com/97efe248949947f97db00414cfa6b58e0d6875c628f85c111b3603780a8b4851-image-20200304162915545.png)


双向节点的值表示key的计数值，我们同一个计数的key 都挂在同一个节点上。有`head, tail`求最大值最小值都在 $O(1)$时间复杂度了。

```python
# 定义双向节点
class Node:
    def __init__(self, cnt):
        self.cnt = cnt
        # 记录该cnt(计数)下key包括哪些?
        self.keySet = set()
        # 前后指针
        self.prev = None
        self.next = None


class AllOne:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        # 记录头尾 便于求最小值最大值
        self.head = Node(float("-inf"))
        self.tail = Node(float("inf"))
        # 首尾相连
        self.head.next = self.tail
        self.tail.prev = self.head
        # 个数对应的节点
        self.cntKey = {}
        # key 对应的个数
        self.keyCnt = {}


    def inc(self, key: str) -> None:
        """
        Inserts a new key <Key> with value 1. Or increments an existing key by 1.
        """
        if key in self.keyCnt:
            self.changeKey(key, 1)
        else:
            self.keyCnt[key] = 1
            # 说明没有计数为1的节点,在self.head后面加入
            if self.head.next.cnt != 1:
                self.addNodeAfter(Node(1), self.head)
            self.head.next.keySet.add(key)
            self.cntKey[1] = self.head.next


    def dec(self, key: str) -> None:
        """
        Decrements an existing key by 1. If Key's value is 1, remove it from the data structure.
        """
        if key in self.keyCnt:
            cnt = self.keyCnt[key]
            if cnt == 1:
                self.keyCnt.pop(key)
                self.removeFromNode(self.cntKey[cnt], key)
            else:
                self.changeKey(key, -1)

    def getMaxKey(self) -> str:
        """
        Returns one of the keys with maximal value.
        """
        return "" if self.tail.prev == self.head else next(iter(self.tail.prev.keySet))

    def getMinKey(self) -> str:
        """
        Returns one of the keys with Minimal value.
        """
        return "" if self.head.next == self.tail else next(iter(self.head.next.keySet))

    # key加1或者减1
    def changeKey(self, key, offset):
        cnt = self.keyCnt[key]
        self.keyCnt[key] = cnt + offset
        curNode = self.cntKey[cnt]
        newNode = None
        if cnt + offset in self.cntKey:
            newNode = self.cntKey[cnt + offset]
        else:
            newNode = Node(cnt + offset)
            self.cntKey[cnt + offset] = newNode
            self.addNodeAfter(newNode, curNode if offset == 1 else curNode.prev)
        newNode.keySet.add(key)
        self.removeFromNode(curNode, key)

    # 在prevNode后面加入newNode
    def addNodeAfter(self, newNode, prevNode):
        newNode.prev = prevNode
        newNode.next = prevNode.next
        prevNode.next.prev = newNode
        prevNode.next = newNode

    # 在curNode删除key
    def removeFromNode(self, curNode, key):
        curNode.keySet.remove(key)
        if len(curNode.keySet) == 0:
            self.removeNodeFromList(curNode)
            self.cntKey.pop(curNode.cnt)

    # 删掉curNode节点
    def removeNodeFromList(self, curNode):
        curNode.prev.next = curNode.next
        curNode.next.prev = curNode.prev
        curNode.next = None
        curNode.prev = None


```





