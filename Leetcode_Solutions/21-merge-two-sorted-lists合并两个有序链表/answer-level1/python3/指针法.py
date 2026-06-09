### 解题思路
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        root = ListNode(None)  # 建立新链表的头结点
        cur = root  #  将当前指针初始为头结点
        while l1 and l2:
            if l1.val <= l2.val:
                # 存放符合合并条件的新节点到node变量
                node = ListNode(l1.val)
                # 删除l1中符合合并条件的这个节点
                l1 = l1.next
            else:
                # 同l1
                node = ListNode(l2.val)
                l2 = l2.next
            # 头结点指向符合合并条件的新节点
            cur.next = node
            # 指针位置前移
            cur = node
        # l1或者l2可能还有剩余的元素，一并添加到指针节点后
        if l1 is not None:
            cur.next = l1
        else:
            cur.next = l2
        # 返回None后面的链表
        return root.next

                 
```