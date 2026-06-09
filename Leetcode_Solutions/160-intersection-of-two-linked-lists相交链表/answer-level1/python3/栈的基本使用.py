### 解题思路
以后类似从链表尾部开始的操作，是不是都可以先考虑下栈
执行用时 :176 ms, 在所有 Python3 提交中击败了55.35% 的用户
内存消耗 :27.8 MB, 在所有 Python3 提交中击败了100.00%的用户
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if not headA or not headB:
            return None
        lista = []
        a = headA
        while a:
            lista.append(a)
            a = a.next

        listb = []
        b = headB
        while b:
            listb.append(b)
            b = b.next

        rtn = None
        while lista[-1]==listb[-1]:
            rtn = lista[-1]
            lista.pop()
            listb.pop()
            if not lista or not listb:
                break
        return rtn

```