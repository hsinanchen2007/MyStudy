```
#! -*- encoding=utf-8 -*-
# 双向链表
class MyNode(object):
    def __init__(self, value):
        self.val = value
        self.next = None
        self.prev = None
    
    def __str__(self):
        return '{%d}' % (self.val)
    
    def __repr__(self):
        return '{%d}' % (self.val)

class MyLinkedList(object):
    
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.size = 0
        self.head = None
        self.tail = None
        

    def get(self, index):
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        :type index: int
        :rtype: int
        """
        if index >= self.size:
            return -1
        else:
            cur = self.head
            for i in range(0, index):
                cur = cur.next
            return cur.val

    def addAtHead(self, val):
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        :type val: int
        :rtype: None
        """
        node = MyNode(val)
        if self.size == 0:
            self.head = node
            self.tail = node
            self.size += 1
        else:
            node.next = self.head
            self.head.prev = node
            self.head = node
            self.size += 1
        

    def addAtTail(self, val):
        """
        Append a node of value val to the last element of the linked list.
        :type val: int
        :rtype: None
        """
        node = MyNode(val)
        if self.size == 0:
            self.head = node
            self.tail = node
            self.size += 1
        else:
            node.prev = self.tail
            self.tail.next = node
            self.tail = node
            self.size += 1
        

    def addAtIndex(self, index, val):
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        :type index: int
        :type val: int
        :rtype: None
        """
        node = MyNode(val)
        if index <= 0:  # index为负，在头部添加
            self.addAtHead(val)
        elif index == self.size:    # index跟链表大小一样，在尾部添加
            self.addAtTail(val)
        elif index > self.size-1:   # index超出链表，不添加
            return
        else:                       # 其他正常情况， 中间插入
            cur = self.head         
            for i in range(0, index):
                cur = cur.next      # 找到当前index的节点
            node.prev = cur.prev    # 往cur前插入
            node.next = cur
            cur.prev.next = node
            cur.prev = node
            self.size += 1

    def deleteAtIndex(self, index): # 这个其实可以再拆分方法出来，像下面这样写一个方法就很长，不美观
        """
        Delete the index-th node in the linked list, if the index is valid.
        :type index: int
        :rtype: None
        """
        if self.size == 0:      # 链表是否为空，为空直接返回
            return
        else:                   # 链表不为空
            if (index >= self.size) or (index < 0):  # 无效index，直接返回
                return
            else:                   # 有效index
                if index == 0:      # 边界处理，删除节点为第一个时
                    if self.head.next:  # 如果有下一个节点
                        self.head = self.head.next
                        self.head.prev = None
                    else:               # 没有下一个节点
                        self.tail = self.head = None
                    self.size -= 1
                elif index == self.size-1:   # 边界处理，删除节点为倒数第一个时
                    if self.tail.prev:  # 如果有上一个节点
                        self.tail = self.tail.prev
                        self.tail.next = None
                    else:               # 没有上一个节点
                        self.tail = self.head = None
                    self.size -= 1
                else:                   # 不在第一个和最后一个节点的情况
                    cur = self.head         
                    for i in range(0, index):
                        cur = cur.next      # 找到当前index的节点
                    cur.prev.next = cur.next
                    cur.next.prev = cur.prev
                    self.size -= 1

    # 增添一个打印链表的方法方便大家调试
    # 打印当前链表
    def print(self):
        p = self.head
        line = ''   # 使用一个变量存储链表的字符串
        while p:
            line += '%s' % p
            p = p.next
            if p:
                line += "=>"
        print (line)
```
