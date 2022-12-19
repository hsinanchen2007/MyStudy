### 解题思路
单向 操作方便
size 方便检查索引
tail 方便尾部操作

self.head = LinkedNode(val,self.head) 一行赋值与连接
index == size 是可插入位置

prev 方便插入和删除操作
注意head和tail在第一次，和删除操作时候的改变
### 代码

```python3
class LinkedNode:
    def __init__(self,val, next_node=None): # single listnode, default next == None
        self.val = val
        self.next = next_node

class MyLinkedList:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.size = 0   # keep track size for index check
        self.head = None
        self.tail = None  # for tail op
        

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        if index<0 or index>self.size-1: # ooi
            return -1
        node = self.head
        for _ in range(index): # index step
            node = node.next
        return node.val
        

    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        self.head = LinkedNode(val,self.head) # new obj;asign val;asign next
        if not self.size: # if first node
            self.size += 1
            self.tail = self.head
        else:
            self.size += 1
        

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        node = LinkedNode(val) # next == None
        if not self.size: # first node
            self.size += 1
            self.head = self.tail = node
        else:
            self.size += 1
            self.tail.next = node # link
            self.tail = self.tail.next # next step   
            
            
    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        if index<0 or index>self.size: # [0,]
            return 
        if index == 0:
            return self.addAtHead(val)
        if index == self.size:
            return self.addAtTail(val)
        prev = LinkedNode(0, self.head) # prev node for op easily
        for _ in range(index):
            prev = prev.next
        prev.next = LinkedNode(val, prev.next) # one line for insert
        self.size += 1
        

    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        if index<0 or index>self.size-1:
            return 
        prev = LinkedNode(0,self.head)
        for _ in range(index):
            prev = prev.next
        prev.next = prev.next.next # del node
        # fix head or tail
        if index == 0:
            self.head = prev.next
        if index == self.size - 1:
            self.tail = prev
        self.size -= 1
        


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
```