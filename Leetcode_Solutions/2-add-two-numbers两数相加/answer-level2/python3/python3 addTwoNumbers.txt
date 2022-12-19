 
1. 当str处理
```crmsh
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        node = l1
        result1 = ""
        while node is not None:
            result1 = str(node.val) + result1
            node = node.next

        result2 = ""
        node = l2
        while node is not None:
            result2 = str(node.val) + result2
            node = node.next

        add = str(int(result1) + int(result2))

        l3 = l4 = ListNode(0)
        for index in range(len(add), 0, -1):
            l3.next = ListNode(int(add[index - 1]))
            l3 = l3.next

        return l4.next
```


2. 每位相加
```livecodeserver
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        add = 0
        l3 = l4 = ListNode(0)
        while l1 or l2 or add:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            num = val1 + val2 + add
            add = 0
            if num // 10 > 0:
                add = 1
                num = num % 10
            l3.next = ListNode(num)
            l3 = l3.next
            l1 = l1.next if l1 else l1
            l2 = l2.next if l2 else l2

        return l4.next

```