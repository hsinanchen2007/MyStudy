### 解题思路
方法一，借助快慢指针反转前半段链表
方法二，借助辅助数组，直接比较

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        pre=ListNode(None)
        oldcur=head
        fast=head
        while fast and fast.next:
            fast=fast.next.next   #注意这里fast要先走，放到后面的话fast指向的head发生了变化，所以fast就发生了变化，就错了
            tmp1=oldcur.next
            oldcur.next=pre
            pre=oldcur
            oldcur=tmp1
        # print(oldcur.val)
        if fast:   #奇数
            oldcur=oldcur.next
        while oldcur:
            if pre.val!=oldcur.val:
                return False
            pre=pre.next
            oldcur=oldcur.next
        return True
        
```

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        tmp=[]
        while head:
            tmp.append(head.val)
            head=head.next
        return tmp==tmp[::-1]
        
```