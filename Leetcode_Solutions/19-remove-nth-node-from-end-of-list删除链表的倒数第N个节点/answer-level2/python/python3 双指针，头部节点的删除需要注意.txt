### 解题思路
此处撰写解题思路
非常简单的双指针，头节点删除和尾节点中间节点删除略有不同，先判断是否要删除头节点，如何判断的？
当前的cur节点还是head节点，同时first节点是None了，说明要删除的是头节点
其余情况都是 中间节点和尾部节点的删除，是一样的性质。
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        cur = first = head
        while n:
            first = first.next
            n-=1
        
        while first and first.next:
            cur = cur.next
            first = first.next

        if cur==head and not first: # 删除头节点
            return cur.next # 没有物理意义上的删除，只是返回了头部节点的下一个节点。
        else:            
            cur.next = cur.next.next # 删除中间节点和尾节点
            # temp = cur.next
            # cur.next = temp.next
            # temp.next = None        
        return head



```