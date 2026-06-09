### 解题思路
实现方法与官方题解类似

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        #加入边界条件判断
        if head is None or head.next is None:
            return True

        #快慢指针找到链表中点。若链表长度为3，则中点为2；长度为4，中点也为2
        slow=head
        fast=head
        while fast.next is not None and fast.next.next is not None:
            slow=slow.next
            fast=fast.next.next

        #对链表中点之后的链表进行翻转，使用自定义reverse函数
        mid=slow.next
        mid=self.reverse(mid)

        #一一比较链表中点前与链表中点后的元素值，若出现不相等则直接返回False
        while mid:
            if head.val!=mid.val:
                return False
            head=head.next
            mid=mid.next
        return True

    #通过双指针实现链表原地翻转，空间复杂度为O(1)
    def reverse(self, head):
        pre=None
        cur=head
        while cur:
            cur.next,cur,pre=pre,cur.next,cur
        return pre
```