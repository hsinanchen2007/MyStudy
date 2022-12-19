86.分隔链表
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
你应当保留两个分区中每个节点的初始相对位置。
输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5
双指针解法,先找到最初分界,l指针指向分界，r指针向后遍历，找到val<x的节点，插入到分界前
时间复杂度O(n),空间复杂度O(1)
```
class Solution:
    def partition(self, head, x):
        if not head or not head.next:
            return head
        # 添加哑结点
        dummy = ListNode(0)
        dummy.next = head
        l = dummy
        # 找到最初的分界线
        while l.next and (l.next.val<x):
            l = l.next
        r = l.next
        while r and r.next:
            if r.next.val<x:
                tempNode = r.next
                r.next = tempNode.next
                tempNode.next = l.next
                l.next = tempNode
                l = l.next
            else:
                r = r.next
            if not r: break
        return dummy.next
```



