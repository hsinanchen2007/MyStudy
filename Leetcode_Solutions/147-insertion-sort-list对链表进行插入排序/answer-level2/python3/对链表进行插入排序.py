### 解题思路
按照题目中的步骤来；

时间复杂度：`O(n**2)`
空间复杂度: `O(1)`

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if not (head and head.next):
            return head
        
        # head到tmp是已经排序好的链表，现将tmp.next插入到head到tmp之间；
        tmp = head
        while tmp.next:
            if tmp.next.val >= tmp.val:
                # 如果tmp.next.val最大，则不用移动，进入下一个循环；
                tmp = tmp.next
            else:
                # 将tmp.next从链表中删除，用node保存tmp.next;
                node = tmp.next
                tmp.next = tmp.next.next
                if head.val >= node.val:
                    # 如果node的值最小，则插入到开头；
                    node.next = head
                    head = node
                else:
                    # 否则，从head开始遍历链表，找到start.val < node.val, start.next.val > node.val的节点；
                    # 将node插入start与start.next之间；进入下一个循环；
                    start = head
                    while start.next.val <= node.val:
                        start = start.next
                    node.next = start.next
                    start.next = node
        return head
```