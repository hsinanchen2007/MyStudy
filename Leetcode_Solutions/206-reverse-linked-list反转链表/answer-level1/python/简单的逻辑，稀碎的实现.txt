### 解题思路
看到要**逆序**，第一反应是利用列表的**list.reverse()**方法，那么所谓思路就是：
1. 将链表内容放进列表里，
2. 列表逆序，
3. 重新组成链表。
卡住我自己的就是新链表的组成，因为对python的链表结构不熟悉，所以组了半天，踉踉跄跄完成了。没考虑时空复杂度，算是菜鸟解吧。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        a,j=[],0
        b=ListNode(0)
        if head:
            while head:
                a.append(head.val)
                head=head.next
            a.reverse()
            for i in range(len(a)):
                a[i]=ListNode(a[i])
        
            while j<len(a)-1:
                a[j].next=a[j+1]
                j+=1
            return a[0]
        else:
            return []

        
            


```