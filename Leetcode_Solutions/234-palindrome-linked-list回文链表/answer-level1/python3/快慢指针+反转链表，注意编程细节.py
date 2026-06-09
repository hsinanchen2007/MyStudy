```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        '''
        快慢指针+反转链表，时间复杂度O(n)，空间复杂度O(1)
        思路：
        快指针faster以两倍速先于慢指针lower,这样当快指针到达末尾时，慢指针正好到达链表中间。
        同时我们在慢指针遍历链表的同时将链表反转，这样，当慢指针到达中间后，
        就可以将原先的链表向两个方向遍历，以用于判断链表是否回文。
        注意点：
        （1）反转链表时，需要用到三个指针，lower_next先指向下一个结点，然后将lower移动到
        lower_next,然后将lower.next之前先前的位置lower_pre，然后将lower_pre移动到lower
        的位置，完成一次链表反转。
        （2）如果lower_pre == head, 那么就需要先将lower_pre.next == None
        （3）注意链表为奇数还是偶数，两种情况分别讨论。
        '''
        lower = head
        faster = head
        lower_pre = head
        if lower == None:
            # 说明空表
            return True
        lower_next = head.next
        if lower_next == None:
            # 说明只有一个结点
            return True
        
        while faster != None and faster.next != None:
            # 快慢指针遍历的同时，反转慢指针遍历的链表
            lower = lower_next
            faster = faster.next.next
            lower_next = lower_next.next
            lower.next = lower_pre
            # 注意头结点的反转
            if lower_pre == head:
                lower_pre.next = None
            lower_pre = lower
        if faster == None:
            # 说明是偶数链表
            if lower.val != lower.next.val:
                return False
            elif lower.next.next == None:
                # 说明链表只有两节，且是回文
                return True
            else:
                left = lower.next.next
                right = lower_next
                while left != None:
                    if left.val != right.val:
                        return False
                    left = left.next
                    right = right.next
                return True
        else:
            # 说明是奇数链表
            left = lower.next
            right = lower_next
            while left != None:
                if left.val != right.val:
                    return False
                left = left.next
                right = right.next
            return True
            
```
