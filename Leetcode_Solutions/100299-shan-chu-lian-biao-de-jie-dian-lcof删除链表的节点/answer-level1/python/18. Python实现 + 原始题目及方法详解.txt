### 解题思路
这道题本身很简单，只想再次提醒一下各位，对于链表修改的问题一定要考虑添加虚拟头结点是否可以避免问题的分类讨论进而降低问题复杂性。
还想记录一下原题及方法，因为想法确实很有趣。
原题：给定单链表头指针和节点指针，删除该指针指向的节点，要求O(1)时间复杂度。
在看到这道题的时候我直接就想到了哈希链表，即结合了哈希表和链表的数据结构，具有哈希表和链表共同的优点，可以做到O(1)时间复杂度的查找和删除，但这道题显然不是。这道题正确的做法是：
（1）若链表只有一个节点，返回nullptr，时间复杂度O(1)；
（2）若链表有不止一个节点且删除尾节点，那么需要head开始遍历找到倒数第二个节点进行删除，时间复杂度O(n)；
（3）若链表有不止一个节点且删除非尾节点，**将下一个节点的val拷贝到当前节点，然后删除下一个节点**，时间复杂度O(1)；
总的时间复杂度为((n - 1) * O(1) + O(n)) / n　= O(1)。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteNode(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        v_head = ListNode(0)
        v_head.next = head
        p = v_head
        while p.next:
            if p.next.val == val:
                break
            p = p.next
        # 考虑有可能val不在链表中 
        if p.next:
            p.next = p.next.next
        return v_head.next
```