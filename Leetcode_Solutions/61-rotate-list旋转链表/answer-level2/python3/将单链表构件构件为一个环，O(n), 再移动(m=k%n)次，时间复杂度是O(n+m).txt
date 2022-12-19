### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        #判断是否为空
        if not head:
            return head
        length = 1
        res = head
        #遍历链表，找到尾结点
        while res.next != None:
            length += 1
            res = res.next
        #res此时指向最后一个节点
        #构建环
        res.next = head
        #res指向更新后的尾结点
        #求移动长度
        move_length = length - k % length

        while move_length > 0:
            #更新res指向的尾结点
            res = res.next
            move_length -= 1
        #新的头指针为update_res的下一个
        head = res.next
        #update_res指向Null
        res.next = None
        return head

```