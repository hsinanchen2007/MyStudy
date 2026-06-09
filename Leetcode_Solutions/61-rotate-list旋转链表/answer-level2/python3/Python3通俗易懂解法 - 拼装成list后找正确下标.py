### 解题思路
思路贼简单, 直接把链表读出来装入list中. 然后算出新的头结点的下标, 再修改回输入链表中. 
时间开销: O(N), 空间开销: O(N)

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head or not k: 
            return head
        assemble_list = []
        p = head
        while p:
            assemble_list.append(p.val)
            p = p.next
        new_head_index = len(assemble_list) - k % len(assemble_list)
        # print("assemble_list", assemble_list, "index", new_head_index)
        p = head
        for e in (assemble_list[new_head_index:] + assemble_list[:new_head_index]):
            p.val = e
            p = p.next
        return head

            
```