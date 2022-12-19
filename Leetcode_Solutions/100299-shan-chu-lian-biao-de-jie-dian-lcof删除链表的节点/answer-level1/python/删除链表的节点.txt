### 解题思路
本题tips：
1. 伪头节点可以简化判断条件，避免考虑删除节点是头节点的情况
2. 双指针可以避免出现next.next的情况

**原题**可能出现的三种情况：
1. 删除的是头节点且链表仅有一个节点：head指向None。时间复杂度：O(1)
2. 删除的是尾节点：倒数第二个节点指向None。时间复杂度：O(N)
3. 删除的是N-1个非尾节点：将待删除节点的后一个节点的值符给待删除节点，然后把其前一个节点指向其后一个节点。这样就等同为删除该节点。时间复杂度：O(1)

平均时间复杂度：O(1)
空间复杂度：O(1)


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        
        cur = head
        pre = dummy

        while cur != None:
            if cur.val == val:
                pre.next = cur.next
                break
            else:
                pre = cur
                cur = cur.next

        return dummy.next
```