### 解题思路
此处撰写解题思路
1. 判断是否包含环形链表：前后两个指针p和q，p指针每次前进一次，q指针每次前进2次，若包含环形链表则p和q一定会相遇
2. 得到环形链表中的node数
3. 从head开始遍历node，并对每一个node，判断是否与环形链表中的node任一相等，若相等则该node为为环形链表的起点。
【但是时间复杂度和空间复杂度都很差！】
其他方法：
    判断是否包含环形链表：前后两个指针p和q，p指针每次前进一次，q指针每次前进2次，记录相遇的节点N；
    通过两个指针，一个从head处起始，一个从从节点N起始遍历，这两个指针第一次相遇的节点即环形链表的起点。
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if (head==None) or (head.next == None) or (head.next.next == None):
            return None
        # 判断单向链表中是否包含环形链表，并将环形链表中的某个node赋值给 head_node和next_node
        head_node = head
        next_node = head.next.next
        while next_node != head_node:
            if (next_node.next == None) or (next_node.next.next==None):
                return None
            head_node = head_node.next
            next_node = next_node.next.next
        # 得到环形链表中的node数 loop_nums
        next_node = next_node.next
        loop_nums = 1
        while head_node != next_node:
            next_node = next_node.next
            loop_nums += 1
        # 从head开始遍历整个listnode，对每个node，判断是否与环形链表中的任一node相等
        check_node = head
        while True:
            for i in range(0,loop_nums):
                if next_node == check_node:
                    return check_node                  
                else:
                    next_node = next_node.next
            check_node = check_node.next
        
```