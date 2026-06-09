### 解题思路
1. 此题的一点疑惑：给的已知的两个链表是否带有头指针 -- 实际上不带头指针；且在原链表上合并。
2. 合并的新链表，需要一个头指针，因为需要标记开头的位置，并指向下一个位置元素（合并后的第一个元素）
3. 自己第一次提交的代码：N/A 不就错误，而且啰嗦，链表是带有指针的，因此最后用if 代替 while即可
4. 一次排列一个元素，因此不需要为每一个链表记录下一个元素，这不同于排列连个元素。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        res = ListNode(0)
        cur = res
        while l1 != None and l2 != None:
            if l1.val <= l2.val:
                cur.next = l1
                l1 = l1.next
                cur = cur.next
            else:
                cur.next = l2
                l2 = l2.next
                cur = cur.next 
        if l1 != None:
            cur.next = l1
        if l2 != None:
            cur.next = l2
        return res.next

```