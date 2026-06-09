分解问题为3个小问题

1. 链表转数
2. 数字相加 
3. 结果数字逆序转链表返回


主程序：
```
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        num1 = self.listnode_to_int(l1)
        num2 = self.listnode_to_int(l2)
        num = num1 + num2
        newln = self.int_to_listnode(num)
        return newln
```


链表转数字：
```

    def listnode_to_int(self, ln):
        l = []
        while ln:
            l.append(str(ln.val))
            ln = ln.next
        l.reverse()
        ls = int(''.join(l))
        return ls
```

数字转链表（此处略坑）：
```
    def int_to_listnode(self, x):
        xs = str(x)
        l = []
        for i in xs:
            node = ListNode(int(i))
            l.append(node)
        node = l.pop()
        head = ListNode(0)
        head.next = node
        while l:
            node.next = l.pop()
            node = node.next
        return head.next
```




最终的完整程序：

```
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        num1 = self.listnode_to_int(l1)
        num2 = self.listnode_to_int(l2)
        num = num1 + num2
        newln = self.int_to_listnode(num)
        return newln

    def int_to_listnode(self, x):
        xs = str(x)
        l = []
        for i in xs:
            node = ListNode(int(i))
            l.append(node)
        node = l.pop()
        head = ListNode(0)
        head.next = node
        while l:
            node.next = l.pop()
            node = node.next
        return head.next

    def listnode_to_int(self, ln):
        l = []
        while ln:
            l.append(str(ln.val))
            ln = ln.next
        l.reverse()
        ls = int(''.join(l))
        return ls
```
