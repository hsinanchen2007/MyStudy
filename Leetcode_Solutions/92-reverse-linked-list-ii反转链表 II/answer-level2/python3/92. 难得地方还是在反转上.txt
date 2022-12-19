### 解题思路
联系n多遍反转的写法

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        dummy_node = ListNode(0)
        dummy_node.next = head

        # 记录下第m-1个节点，因为后面要把这个节点指向翻转后的节点上去
        fix_m = dummy_node
        for i in range(m-1):
            fix_m = fix_m.next
        
        # 开始反转
        pre = None
        cur = fix_m.next
        for i in range(n-m+1):
            temp = cur.next
            cur.next = pre
            pre = cur
            cur = temp

        fix_m.next.next = cur
        fix_m.next = pre
        return dummy_node.next
```