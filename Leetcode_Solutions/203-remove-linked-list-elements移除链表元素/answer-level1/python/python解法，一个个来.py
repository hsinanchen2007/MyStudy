![image.png](https://pic.leetcode-cn.com/10df5094305da614da78f3ad3c05229b7073e14c4a4fcf6c4e4e417c7388f9f3-image.png)

瞎蒙出来的时间orz， 思路很简单，一个个去找。

```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        #先清除开头所有和val相等的节点
        while head and head.val==val:
            head=head.next
        #然后设立指针p，一个个向后找
        p=head
        #找到符合的就删掉它指向下一个
        while p:
            if p.next and p.next.val==val:
                p.next=p.next.next
            else:
                p=p.next
        #返回头结点
        return head
```





