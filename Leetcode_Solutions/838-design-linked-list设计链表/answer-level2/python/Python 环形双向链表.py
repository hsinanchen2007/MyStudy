```python
class Node:
    def __init__(self, v, p=None, n=None):
        self.val = v
        self.prev = p
        self.next = n

class MyLinkedList:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.key = Node(-1)
        self.key.prev = self.key.next = self.key

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        i, node = 0, self.key.next
        while i < index and node != self.key:
            node = node.next
            i += 1
        return node.val if index >= 0 else -1

    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        self.key.next.prev = self.key.next = Node(val, p=self.key, n=self.key.next)

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        self.key.prev.next = self.key.prev = Node(val, p=self.key.prev, n=self.key)

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        index = max(0, index)
        i, node = 0, self.key.next
        while i < index and node != self.key:
            node = node.next
            i += 1
        if node != self.key or i == index:
            node.prev.next = node.prev = Node(val, p=node.prev, n=node)

    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        if index < 0: return
        i, node = 0, self.key.next
        while i < index and node != self.key:
            node = node.next
            i += 1
        if node != self.key:
            node.prev.next = node.next
            node.next.prev = node.prev
            del node


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
```
- 本题构建了一个双向的环形链表，记录 key 节点，key.next 指向链表的 head，key.prev 指向链表的 tail