### 解题思路
首先和环形链表I中一样，设置两个指针p1和p2，p1每次往前一步，p2每次往前2步
如果p2指向空，那么说明没有链存在
否则，p1和p2最后会在一个节点相聚，这时候p1走过的步数m就是循环的步数，这时候设置两外两个指针，分别从头节点和上述相遇节点出发
每次前进一步，当两个指针指向的节点相同时，这个节点就是进入循环的节点。返回这个节点作为结果

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        p1 = p2 = head
        steps = 0
        while p2:
            steps += 1
            p1= p1.next
            p2 = p2.next
            if p2:
                p2 = p2.next
            if p1 == p2:
                break
        
        if not p2:
            return None
        p1 = head
        while p1 != p2:
            p1 = p1.next
            p2 = p2.next
        return p1

```