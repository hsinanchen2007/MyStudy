### 解题思路-快慢指针
与141题相似，构造两个指针`slow, fast`，其中`slow=slow.next, fast=fast.next.next`；若有环，则`slow, fast`会在环内节点`cross`相遇；相遇之后，为了找到入口节点，令`slow=head, fast=cross`，此时令`slow=slow.next, fast=fast.next`，再次相遇的节点即为入口节点；

证明：假设环外节点数为m，环内节点数为n，假设`slow`指针走了k步，则`fast`指针走了`2k`步，相遇节点位置为`k-m`；由于两者在环内分别走了`k-m, 2k-m`步；则`2k-m-(k-m)=k`是n的整数倍；因此，当`slow=head, fast=k-m`，令`slow=slow.next, fast=fast.next`，当`slow, fast`均走了m步，此时`slow=m, fast=k`，均在环的入口处。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    """
    快慢指针法：
    同141题，设置两个指针slow,fast，其中slow每次走一步，fast每次走两步；找到相遇点cross；
    然后设置slow=head, fast=cross；两个指针均每次都走一步；最终两者相遇的结点为入口节点；
    """
    def detectCycle(self, head: ListNode) -> ListNode:
        if not (head and head.next):
            return None
        
        slow, fast = head, head
        while slow and fast:
            slow, fast = slow.next, fast.next
            fast = fast.next if fast else None
            if slow == fast:
                break
                
        if not fast:
            return None
        
        slow = head
        while slow != fast:
            slow, fast = slow.next, fast.next
        return slow
```