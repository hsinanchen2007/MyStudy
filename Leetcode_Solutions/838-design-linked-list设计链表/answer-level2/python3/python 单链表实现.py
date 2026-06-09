题目不是说链表的值都在[1,1000]么？
还有还有插入在-1位置都可以算对
好吧，经过半天调试终于过了
```python3
class Node(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class MyLinkedList:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.head=Node(-1)
        

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        tmp=self.head
        ti=0
        while tmp:
            if ti==index:
                if tmp.val==-1:
                    return -1
                else:
                    return tmp.val
            tmp=tmp.next
            ti+=1
        return -1

    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        if self.head.val==-1:
            self.head=Node(val)
        else:
            newhead=Node(val)
            newhead.next=self.head
            self.head=newhead

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        tmp=self.head
        while tmp:
            if not tmp.next:
                tmp.next=Node(val)
                return
            tmp=tmp.next
        

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        
        if self.head.val==-1:
            if index<=0:
                self.addAtHead(val) 
            return
        if index<=0:
            self.addAtHead(val)
            return
        tmp=self.head
        ti=0
        while tmp:
            if ti==index-1:
                if tmp.next:
                    n=Node(val)
                    n.next=tmp.next
                    tmp.next=n
                    return
                else:
                    tmp.next=Node(val)
                    return
            tmp=tmp.next
            ti+=1
        return 
                
                
                

    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        if self.head.val==-1:
            return
        if index==0:
            self.head=self.head.next
            return
        tmp=self.head
        ti=0
        while tmp:
            if ti==index-1:
                if tmp.next:
                    if tmp.next.next:
                        tmp.next=tmp.next.next
                        return
                    else:
                        tmp.next=None
                        return
                else:
                    return
            tmp=tmp.next
            ti+=1
            


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
```