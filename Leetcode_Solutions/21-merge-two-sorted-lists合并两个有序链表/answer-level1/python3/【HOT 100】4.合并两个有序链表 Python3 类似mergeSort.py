
看到合并两个有序链表就想到归并排序（虽然我好像也忘了。。）

循环遍历两个链表，比较大小，小的就先接在合并链表之后，然后更新当前节点和合并链表的节点，
循环条件为两个链表都不为None，出循环要么一个为None要么两个为None，那么就在出循环后判断，哪个链表还有值，就接在合并的链表之后

![image.png](https://pic.leetcode-cn.com/cc2a3b399fcf18892c33fcc9acbb63fbbcc77ecd0e9cbf93c9f127759a1c6f8c-image.png)

```
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        
        head = ListNode(0)
        tmp = head
        
        while l1 and l2:
            if l1.val <= l2.val:
                tmp.next = l1
                l1 = l1.next
            else:
                tmp.next = l2
                l2 = l2.next
            tmp = tmp.next
        
        if l1:
            tmp.next = l1
        if l2:
            tmp.next = l2
            
        return head.next
```

**时间复杂度为O(m+n)链表的长度之和，空间复杂度为O(1)**

![image.png](https://pic.leetcode-cn.com/21eaddc2fe40f3502718a143f9817071dc56e7b3cd3830d0c1aa5f335531ce22-image.png)
