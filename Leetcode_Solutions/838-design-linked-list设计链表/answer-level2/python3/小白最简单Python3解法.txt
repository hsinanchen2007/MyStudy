### 解题思路

小白最简单Python3解法：

除了本身的链表MyLinkedList类，另外定义一个结点类Node。每个节点包括结点本身的value以及指向后面一个结点的指针next。最好定义一个size变量，用来记录链表长度，便于后续判断。

容易犯的错误:
1. 注意空链表的初始化。我这里没有使用dummy node，直接将头结点初始化为None，而不是一个空结点。
2. 注意后续遍历的循环次数。查找是循环到index位置，增加删除是循环到index前结点


### 代码

```python3
class Node(object):
"""
定义一个节点类Node
"""
    def __init__(self,x):
        self.val = x
        self.next = None

class MyLinkedList:

    def __init__(self):
    """
    Initialize your data structure here.
    注意将头结点初始化为None，而不是Node(0)或者Node(None)
    """
        self.head = None
        self.size = 0

    def get(self, index: int) -> int:
    """
    Get the value of the index-th node in the linked list. If the index is invalid,    return -1. 
    查找指定位置节点的值。注意控制链表为空/指定位置无效的情况。
    """
        if self.size == 0: return -1
        elif index < 0 or index > self.size-1: return -1

        node = self.head
        for i in range(index):
                node = node.next
        return node.val
    
    def addAtHead(self, val: int) -> None:
    """
    Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
    在头部插入新结点。如果链表为空，则将新结点直接置为头结点。
    """
        if self.size == 0:
            self.head = Node(val)
            self.size += 1        
        else:
            node = Node(val)
            node.next = self.head
            self.head = node
            self.size += 1

    def addAtTail(self, val: int) -> None:
    """
    Append a node of value val to the last element of the linked list.
    在尾部插入新结点。如果链表为空，则将新结点设为头结点。
    """
        if self.size == 0:
            self.head = Node(val) 
            self.size += 1
        
        else:
            node = self.head
            while node.next != None:
                node = node.next
            node.next = Node(val)
            self.size += 1

    def addAtIndex(self, index: int, val: int) -> None:
    """
    Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
    在指定位置插入新结点。如果指定位置小于等于0，则插入到头结点。如果指定位置在链表尾部，则插入到尾部。
    """
        new = Node(val)
        if index <= 0:
            self.addAtHead(val)
        if index > self.size:
            return -1
        else:
            node = self.head
            for i in range(index-1):
                node = node.next
            if node.next == None:
                node.next = new
                self.size += 1
            else:
                new.next = node.next 
                node.next = new
                self.size += 1
                
    def deleteAtIndex(self, index: int) -> None:
    """
    Delete the index-th node in the linked list, if the index is valid.
    删除指定位置结点。指定位置不得小于0，或大于链表长度。链表本身不能为空。如果指定位置为头结点，则把头结点移动到第二个结点。如果指定位置为尾结点，则直接释放尾结点。
    """           
        if index < 0 or index > self.size-1 or self.size == 0:
            return -1
        
        elif index == 0:
            node = self.head
            self.head = node.next
            self.size -= 1
            
        else:
            node = self.head
            for i in range(index-1):
                node = node.next
            tem = node.next
            if tem.next == None:
                node.next = None
                self.size -= 1
            else:
                node.next = tem.next
                self.size -= 1


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
```