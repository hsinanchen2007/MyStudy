**双栈法：**
    - @关键点：
        1. 两数相加由于是从低位加到高位，需要从最后的节点开始，可以想到用栈来解决
    - @思路：
        1. 先将两个链表的每个值存入栈中，然后将每个栈中对应位置的节点相加
        2. 进位通过一个变量保存，每次迭代都将该值加上
    - @注意点：
        1. 创建链表时，要用 头插法，否则链表是反的
        2. 判断迭代是否可以继续时，要注意当进位值存在时也需要继续，因为可能出现两个栈都空但存在进位的情况

```python
    def addTwoNumbers(self, l1: ListNode, l2: ListNode):
        s1, s2 = [], []
        # 构建两个栈
        while l1: s1, l1 = s1 + [l1.val], l1.next
        while l2: s2, l2 = s2 + [l2.val], l2.next
        dummy = ListNode(-1)
        carry = 0
        
        # 若两栈不为空，或进位数不为空，则都需要继续迭代
        while s1 or s2 or carry:
            n1, n2 = 0, 0
            if s1: n1 = s1.pop() or 0
            if s2: n2 = s2.pop() or 0
            count = carry + n1 + n2
            n = count % 10
            # 头插法创建链表
            node = ListNode(n)
            node.next = dummy.next
            dummy.next = node
            # 下一次迭代的进位数
            carry = int(count / 10)
        
        return dummy.next
```