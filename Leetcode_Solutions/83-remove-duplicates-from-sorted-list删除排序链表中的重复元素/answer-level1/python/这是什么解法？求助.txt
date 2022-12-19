### 解题思路
引用对象操作

### 代码

```python3
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        node = head
        # print(node)
        if head == None:
            return head
        if head.next == None:
            return head
        

        val_list = []
        while node:
            val_list.append(node.val)
            node = node.next
            if node == None:
                break

        # print(val_list)
        is_same = True if len(list(set(val_list))) == 1 else False 
        if is_same:
            head.next = None
            return head
        list_node = []
        for i  in val_list:
            if head.next == None:
                break
            if head.val == head.next.val:
                head.next = head.next.next
                continue
            list_node.append(head)
            # print(list_node)
            head = head.next
        # print(list_node)
        return list_node[0]
```