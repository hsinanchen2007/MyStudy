### 解题思路
理解一点：
slow,fast相遇时的交点，向后走，距离环起点的距离，等于从head到环起点的距离
画个图就可以看出来的，a为head到环初始点距离，假设现在slow走了m,fast走了2m，相遇了，slow距离head的距离：m
fast比slow多走一圈，所以m的距离也是环的长度。slow距离环初始点m-a,再走a距离，即可到达环初始点，
head距离环初始点也是a，所以head,slow再循环即可。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return None
        slow = head.next
        fast = head.next.next
        while fast != slow:
            if fast==None or fast.next == None:
                return None
            slow = slow.next
            fast = fast.next.next
        while head != slow:
            head = head.next
            slow = slow.next

        return head

```