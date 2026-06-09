### 解题思路
- 思路：找到要删除节点的前一个节点的位置，pre.next = pre.next.next删除即可
- 1.考虑到如果要删除头节点的特殊性，所以要增加哨兵节点
- 2.通过遍历整个链表来统计链表的长度length，再通过n与length的关系定位到前一节点


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
    
        #创建哨兵节点(用来处理删除头节点的情况)
        S_node = ListNode(0)
        #指向头节点
        S_node.next = head
        pre = S_node
        length = 0 #计算链表的长度
        
        #计算链表的长度
        while head!=None:
            length += 1
            head = head.next
        #找到要删除节点的前一节点位置（此处考虑到哨兵节点的情况）
        size = length-n
        for i in range(size):
            pre = pre.next
        #删除节点
        pre.next = pre.next.next
        return S_node.next

        




```