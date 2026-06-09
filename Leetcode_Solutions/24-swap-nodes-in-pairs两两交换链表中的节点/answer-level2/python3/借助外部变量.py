### 解题思路
此处撰写解题思路
1. 偶数步前进，每前进一步就替换当前位置与下一个位置；
2. 需要注意链表元素个数，如果为奇数则最后一个元素不用替换；
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        temp = ListNode(0)
        node = temp
        i = 0
        while head != None:
            i += 1
            if i % 2 == 0:
                head = head.next
                continue
            # 如果链表是奇数个，则下一个元素为空，不需要交换位置
            if head.next != None:
                temp.next = ListNode(head.next.val)
                temp = temp.next
            # 两两替换位置
            temp.next = ListNode(head.val)
            temp = temp.next
            head = head.next
        return node.next
```