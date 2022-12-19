### 解题思路
用数组来存放链表

### 代码

```python3
class MyLinkedList:
    # 作者：zhangbin23
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.linked_list = []

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        if 0 <= index <= len(self.linked_list)-1:
            return self.linked_list[index]
        else:
            return -1

    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        self.linked_list.insert(0,val)

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        self.linked_list.append(val)

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        if index <= len(self.linked_list):
            self.linked_list.insert(index,val)

    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        if 0 <= index <= len(self.linked_list)-1:
            return self.linked_list.pop(index)

# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)




# class Node:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# class MyLinkedList:

#     def __init__(self):
#         """
#         Initialize your data structure here.
#         """
#         self.head = None
#         self.size = 0
        
#     def get(self, index: int) -> int:
#         """
#         Get the value of the index-th node in the linked list. If the index is invalid, return -1.
#         """
#         if self.size == 0:
#             return -1
#         elif index < 0 or index > self.index - 1:
#             return -1
#         node = self.head
#         for i in range(index):
#             node = node.next
#         return node.val
        

#     def addAtHead(self, val: int) -> None:
#         """
#         Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
#         """
#         if self.size == 0:
#             self.head = Node(val)
#             self.size += 1
#         else:
#             node = Node(val)
#             node.next = self.head
#             self.head = node
#             self.size += 1
        

#     def addAtTail(self, val: int) -> None:
#         """
#         Append a node of value val to the last element of the linked list.
#         """
#         if self.size == 0:
#             self.head = Node(val)
#             self.size += 1
#         else:
#             node = self.head
#             while node.next:
#                 node = node.next
#             node.next = Node(val)
#             self.size += 1
        
#     def addAtIndex(self, index: int, val: int) -> None:
#         """
#         Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
#         """
#         new = Node(val)
#         if index <= 0:
#             self.addAtHead(val)
#         if index > self.size:
#             return -1
#         else:
#             node = self.head
#             for i in range(index - 1):
#                 node = node.next
#             if node.next == None:
#                 node.next = new
#                 self.size += 1
#             else:
#                 new.next = node.next
#                 node.next = new
#                 self.size += 1    

#     def deleteAtIndex(self, index: int) -> None:
#         """
#         Delete the index-th node in the linked list, if the index is valid.
#         """
#         if index < 0 or index > self.size - 1 or self.size == 0:
#             return -1 
#         elif index == 1:
#             node = self.head
#             self.head = node.next
#             self.size -= 1
#         else:
#             node = self.head
#             for i in range(index - 1):
#                 node = node.next
#             tmp = node.next
#             if tmp.next == None:
#                 node.next = None
#                 self.size -= 1
#             else:
#                 node.next = tmp.next
#                 self.size -= 1
        


# # Your MyLinkedList object will be instantiated and called as such:
# # obj = MyLinkedList()
# # param_1 = obj.get(index)
# # obj.addAtHead(val)
# # obj.addAtTail(val)
# # obj.addAtIndex(index,val)
# # obj.deleteAtIndex(index)
```