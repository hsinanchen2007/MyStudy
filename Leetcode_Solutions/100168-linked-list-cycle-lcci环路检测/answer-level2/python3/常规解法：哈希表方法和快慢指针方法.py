### 解题思路
+ 方法一：哈希表
    + 遍历链表，然后将节点依次存入哈希表，存入之前判断表中是否存在该结点，
    + 如果存在，则返回该结点
    + 如不存在，则结束循环返回None

+ 方法二：快慢指针
    + 快慢指针是这道题的经典解法，就是定义两个指针fast\slow
    + fast每次走两步，slow每次走一步。如果存在环，则fast和slow一定会相遇
    + 如果相遇：
        + 则将slow放到链表开头，然后fast和slow一起“向后走”，当再次相遇的时候，就是环形链表的入口节点
        + 原理就是当第一次相遇的时候，从头结点到入口节点的距离和从相遇点到入口节点的距离是一样的
    + 如果没有相遇：
        + 跳出循环，返回None

> 快慢指针是这种问题的经典解法，除此之外，快慢指针还可以用于找到链表的中间节点（fast遍历到尾节点，此时fast节点所指向的就是中间节点）



### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        """
        遍历链表进哈希表，然后判断是否存在环
        :param head:
        :return:
        """
        p = head
        hash_dict = {}
        while p:
            if p in hash_dict:
                return p
            hash_dict[p], p = p, p.next

        return None

    def detectCycle2(self, head: ListNode) -> ListNode:
        """
        快慢指针（不占用额外空间）
        :param head:
        :return:
        """
        fast = head
        slow = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                slow = head
                while slow != head:
                    slow = slow.next
                    fast = fast.next
                return slow
        return None
            
```