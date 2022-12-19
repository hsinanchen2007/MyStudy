### 解题思路
分两种情况来看：
（1）K的值小于链表长度length：那么新链表的new_head就在原来链表的倒数第k的位置处，也就是顺着数第(length-k+1)处
此时，只需将new_head指向(length-k+1)位置处,然后将old_tail指向old_head处，new_head前一个位置指向None即可
（2）当K的值大于链表的长度：相当于循环了好几圈，使用K=K%length,然后用（1）中方式来求解
注意：当K%length==0：代表正好循环整数圈，此时相当于没有移动，直接返回head
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if head == None:
            return None
        if head.next == None:
            return head

        length  = 1
        ptr = head
# 求出链表的长度
        while ptr.next != None:
            ptr=ptr.next
            length += 1
# 求余==0表示正好移动了整数圈，相当没有移动，直接返回
        if k%length == 0:
            return head
        steps = length - k%length
        top = head
# 找出new_head前一个的位置
        while steps != 1:
            top = top.next
            steps -= 1
        temp = top.next
        ptr.next = head
        top.next = None
        head = temp
        return head






```