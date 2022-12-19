## 思路:

不能翻转，可以借用栈，压入栈中，按栈顶元素相加即可！

## 代码:

```python
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        stack1 = []
        stack2 = []
        dummy = ListNode(-1)
        #
        def push_stack(p, stack):
            while p:
                stack.append(p.val)
                p = p.next
                
        push_stack(l1, stack1)
        push_stack(l2, stack2)
        # 记录进位
        carry = 0
        while stack1 or stack2 or carry:
            tmp1, tmp2 = 0, 0
            if stack1:
                tmp1 = stack1.pop()
            if stack2:
                tmp2 = stack2.pop()
            carry, mod = divmod(tmp1 + tmp2 + carry, 10)
            # 头插法
            new_node = ListNode(mod)
            new_node.next = dummy.next
            dummy.next = new_node
        return dummy.next
```

