### 解题思路
此处撰写解题思路
1. 构建一个中间链表（最开始赋任意值）和一个哑链表；
2. 遍历两个链表的元素值，相加，需要注意是否超过10；
3. 用中间链表的下一个值指向两链表的元素和；
4. 最后判断最后一个节点的和是否超出10；
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 == None:
            return l2
        elif l2 == None:
            return l1
        flag = 0
        temp = ListNode(0)
        node = temp
        while l1 != None or l2 != None:
            val1 = l1.val if l1 != None else 0
            val2 = l2.val if l2 != None else 0
            sum_val = val1 + val2 + flag
            flag = sum_val // 10
            # 一定要给temp的下一个元素赋值，否则亚节点的值不变。
            temp.next = ListNode(sum_val % 10)
            temp = temp.next
            if l1 != None: l1 = l1.next
            if l2 != None: l2 = l2.next
            # print(temp)
        if flag > 0:
            temp.next = ListNode(flag)
        return node.next
```