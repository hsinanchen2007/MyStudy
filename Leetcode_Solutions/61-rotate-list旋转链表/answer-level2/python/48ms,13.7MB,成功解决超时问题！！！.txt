### 解题思路
**双指针法**
1.获取链表长度l
2.k对长度l取余，避免多次循环
3.后指针先走k步
4.双指针一起走，直到后指针到链表尾
5.记录头指针，将链表截断，翻转。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head:return head
        # 获取链表长度
        l = 0
        node = head
        while node:
            l+=1
            node = node.next
        k = k % l # 取余，避免重复循环
        if k == 0:
            return head
        pre,post = head,head    # 定义双指针
        for i in range(k):
            post = post.next    # 后指针先走K步
        while post.next:        # 一起走，直到后指针走到链表尾端
            pre = pre.next
            post = post.next

        tmp = pre.next          # 记录头结点
        pre.next = None         # 将链表截断
        post.next = head        # 将链表翻转连接
        return tmp
    
        

        

```