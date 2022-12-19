
* 我们知道，移除操作需要保留上一个节点。于是，我们不如站在`curr`来看`curr.next`的情况。`curr`初始化为哑结点。
* 如果`curr.next`需要移除，`curr`处的节点跳过后面的节点，连向后面的后面的节点，`curr`按兵不动。
* 如果`curr.next`不需要移除，`curr`向右移一个。
* 直到`curr`移到最后一个节点，即`curr.next`为空。
* 时间复杂度: O(n), 空间复杂度: O(1)

```python []
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        curr = dummy
        while(curr.next):
            if curr.next.val == val:
                curr.next = curr.next.next
            else:
                curr = curr.next
        return dummy.next
```