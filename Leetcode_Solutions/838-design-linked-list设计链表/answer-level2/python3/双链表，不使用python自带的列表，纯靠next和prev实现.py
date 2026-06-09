#在写的时候报了很多错，发现是题目没有好好读庆祝，有几个值得注意的地方如下：
1、addAtIndex(index,val)  如果index小于0，则在头部插入节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾
2、deleteAtIndex(index)，负数的index一律是无效的
3、最好设置哑节点，这对在开头添加一个节点有很大的帮助
4、由于是双链表，所以删除末尾节点的时候，注意prev




class ListNode:

    def __init__(self,val):
        self.val = val
        self.next = None
        self.prev = None


class MyLinkedList:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.dummy = ListNode(0)
        
        
    def size(self):
        count = 0
        cur = self.dummy.next
        while cur != None:
            cur = cur.next
            count += 1
        return count
        

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        if index > self.size()-1:
            return -1
        
        elif index == 0:
            return self.dummy.next.val
        
        
        elif index <0:
                return -1 
                
                
        count = 0
        cur = self.dummy.next
        while count != index:
            cur = cur.next
            count += 1

        return cur.val
        

    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        node = ListNode(val)
        node.next = self.dummy.next
        self.dummy.next = node
        
        return
        
        

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        if self.dummy.next == None:
            self.addAtHead(val)
            return
        
        node = ListNode(val)
        cur = self.dummy.next
        while cur.next != None:
            cur = cur.next
        
        cur.next = node
        node.prev = cur
        return 
        

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        if index == self.size():
            self.addAtTail(val)
            return
        if index >self.size():
            return
        
        if index < 0:
            self.addAtHead(val)
            return 
        
        node = ListNode(val)
        cur = self.dummy.next
        pre = self.dummy
        count = 0
        while count != index:
            pre = cur
            cur = cur.next
            count += 1
        node.next = cur
        cur.pre = node
        node.prev = pre
        pre.next = node
        
    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        
        if index > self.size()-1:
            return
        
        if index < 0:
            return 
                
        cur = self.dummy.next
        pre = self.dummy
        count = 0
        while count != index:
            pre = cur
            cur = cur.next
            count += 1
            
        pre.next = cur.next
        if cur.next != None:
            cur.next.prev = pre


        

