#### 第一种解法:栈
第一个想到的解法就是栈
```python
    def reverseList(self, head: ListNode) -> ListNode:
        s = [] 
        re_point = ListNode(0)
        re = re_point
        while head:
            s.append(head) # 把节点放入栈
            head = head.next
        while s:
            re.next = s.pop() # 出栈并链接节点
            re = re.next
        re.next = None
        return re_point.next
```

#### 第二种解法:迭代
```python
def reverseList(self, head: ListNode) -> ListNode:
        prev = None
        cur = head
        while cur:
            next = cur.next # 标记节点
            cur.next = prev
            prev = cur
            cur = next
        return prev
```

#### 第二种解法:递归
```python
def reverseList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head # 返回原链表为节点作为头结点
        point = self.reverseList(head.next) # 下探
        head.next.next = head # 链接新链
        head.next = None
        return point 返回新链表头结点
```
