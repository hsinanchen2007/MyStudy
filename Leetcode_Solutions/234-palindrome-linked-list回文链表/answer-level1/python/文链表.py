### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        # 想法：先逆序，再比较每一个节点的值，但是不晓得怎么调通。。。
        # p, rev = head, None
        # while p:
        #     rev, rev.next, p = p, rev, p.next 
        
        # while rev and head:
        #     if rev.val == head.val:
        #         rev = rev.next
        #         head = head.next
        #     else:
        #         return False
        # return True
        
        # 方法2: 读出所有的值，看值的逆序是否回文
        # 作者：leetCode-Solution
        vals = []
        current_node = head
        while current_node is not None:
            vals.append(current_node.val)
            current_node = current_node.next
        return vals == vals[::-1]

```