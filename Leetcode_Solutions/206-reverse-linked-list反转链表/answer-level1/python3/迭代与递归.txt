### 解题思路
#### 1、遍历成数组，顺序构建
#### 2、从第二个开始遍历向前进行头插法构建
```
1. pre->1->NULL             2->3->4->5->NULL
2. pre->2->1->NULL          3->4->5->NULL
3. pre->3->2->1->NULL       4->5->NULL
4. pre->4->3->2->1->NULL    5->NULL
5. pre->5->4->3->2->1->NULL NULL
return pre.next
```
#### 3、遍历每一个节点并将其指向之前的节点构成的链表
```
1. NULL<-1                  2->3->4->5->NULL
2. NULL<-1<-2               3->4->5->NULL
3. NULL<-1<-2<-3            4->5->NULL
4. NULL<-1<-2<-3<-4         5->NULL
5. NULL<-1<-2<-3<-4<-5      NULL
```

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        '''迭代法'''
        pre =None
        while head:
            node = head
            head =head.next
            node.next=pre
            pre=node
        return pre

    def reverseList(self, head: ListNode) -> ListNode:
        '''递归法'''
        def dprever(pre,post):
            if post is None:return pre
            node = post
            post=post.next
            node.next=pre
            pre=node
            return dprever(pre,post)
        return dprever(None,head)
            
```