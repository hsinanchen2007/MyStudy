### 解题思路
迭代注意是  cur_node, prev_node, next_node 三者的替代，最后返回prev_node
递归注意 
1. p一直是末尾节点, 用于返回
2. 随着递归深入，head到None后返回
3. 随着递归的退出，head从末尾节点到首节点
4. head.next = None # 取消前向的连接，避免有环

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        """迭代，注意从cur=head开始,返回prev"""
        if head == None: return head
        cur_node = head
        prev_node = None
        while (cur_node):
            next_node = cur_node.next
            cur_node.next = prev_node
            prev_node = cur_node
            cur_node = next_node
        return prev_node

    def reverseList2(self, head: ListNode) -> ListNode:
        """递归"""
        if head == None or head.next == None: return head
        p = self.reverseList2(head.next) # p  一直是末尾节点
        head.next.next = head # 随着递归的退出，head从末尾节点到首节点
        head.next = None # 取消前向的连接，避免有环
        return p
```