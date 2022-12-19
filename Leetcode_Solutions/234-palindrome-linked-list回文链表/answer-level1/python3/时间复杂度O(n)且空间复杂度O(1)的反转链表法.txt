### 解题思路
1. 先通过快慢指针，找到链表的中心点，有2种情况，如果节点是奇数个，慢指针正好指向中心点，如果是偶数个，节点指向中心点的前一个位置；
2. 从慢指针开始切分，慢指针的下一个节点变成第2个链表的开始，同时设置慢指针的下个节点为空，把链表截断；
3. 反转第2个链表；
4. 因为第2个链表要么和第1个链表一样长，要么少1个中心节点，所以通过第2个链表开始遍历，依次判断值和第1个链表是否相等。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head:
            return True
        #拆分链表
        slow,fast=head,head
        while fast.next and fast.next.next:
            slow=slow.next
            fast=fast.next.next
        fst=head
        sec=slow.next
        slow.next=None
        #反转链表2
        prev,curr=None,sec
        while curr:
            next=curr.next
            curr.next=prev
            prev=curr
            curr=next
        sec=prev
        #依次比较2个链表的值
        while sec:
            if sec.val!=fst.val:
                return False
            sec=sec.next
            fst=fst.next
        return True
```