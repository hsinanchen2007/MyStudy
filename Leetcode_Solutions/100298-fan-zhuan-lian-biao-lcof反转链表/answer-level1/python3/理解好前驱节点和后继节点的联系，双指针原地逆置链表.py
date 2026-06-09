双指针原地逆置链表

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head==None:            #先判断链表是否为空
            return None
        r=head.next               #对于第一个节点因为逆置后是最后一个所以先指向空
        head.next=None
        while r!=None:            #遍历链表
            p=head                #标记前驱
            head=r                #标记当前节点
            r=r.next              #存储后继节点
            head.next=p           #使当前节点指向前驱
        return head               #返回新的首节点
        

```