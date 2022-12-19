### 解题思路
1.先遍历两个链表 判断链表长度
2.选用长的那条链表,主链表,数据修改，进位
3.短链表遍历结束,判断长链表第一位值是否等于10
4.不是的话就直接返回

代码还可以适当封装
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        s_n = l1
        e_n = l2
        s = l1
        e = l2
        s_num = 0
        while s_n:
            s_num += 1
            s_n = s_n.next
        e_num = 0
        while e_n:
            e_num += 1
            e_n = e_n.next
        if s_num > e_num:
            while s and e:
                s_e_sum = s.val + e.val
                if s_e_sum > 9:
                    s.val = s_e_sum % 10
                    if s.next is None:
                        s.next = ListNode(1)
                        s = s.next
                        e = e.next
                    else:
                        s = s.next
                        e = e.next
                        s.val = s.val +1
                else:
                    s.val = s_e_sum
                    s = s.next
                    e = e.next
            while s:
                if s.val == 10:
                    s.val = 0
                    if s.next is None:
                        s.next = ListNode(1)
                        s = s.next
                    else:
                        s = s.next
                        s.val = s.val + 1
                else:
                    return l1
            return l1
        else:
            while s and e:
                s_e_sum = s.val + e.val
                if s_e_sum > 9:
                    e.val = s_e_sum % 10
                    if e.next is None:
                        e.next = ListNode(1)
                        s = s.next
                        e = e.next
                    else:
                        s = s.next
                        e = e.next
                        e.val = e.val +1
                else:
                    e.val = s_e_sum
                    s = s.next
                    e = e.next
            while e:
                if e.val == 10:
                    e.val = 0
                    if e.next is None:
                        e.next = ListNode(1)
                        e = e.next
                    else:
                        e = e.next
                        e.val = e.val + 1
                else:
                    return l2
            return l2
```