### 解题思路
中间节点的特征是向前和向后遍历相同次数，可达到头结点和尾节点，因此用一个变量记录从头结点遍历到当前节点需要的个数，再向下遍历同样数目的节点，如果是尾节点，那就找到了目标。在总数目为偶数的链表中，需要向后遍历的个数-1。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        past = 0 //记录遍历过的节点个数
        while True:
            head_copy = head
            cur = past
            while cur != 0:
            // 向后遍历，查看是否能到达尾结点
                if head_copy.next != None:
                    head_copy = head_copy.next
                    cur -= 1
                else:
                    break
            if (cur == 0 or cur == 1) and head_copy.next == None:
                return head
            else:
                past += 1
                head = head.nex
```