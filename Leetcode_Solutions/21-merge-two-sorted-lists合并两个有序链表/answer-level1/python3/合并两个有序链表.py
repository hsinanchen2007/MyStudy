### 迭代法

* 3个指针：`ptr1`和`ptr2`指向两个链表，`ptr3`指向新合成的链表。
* 时间复杂度: O(m+n), 空间复杂度: O(1)

```python []
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode(0)
        ptr1, ptr2, ptr3 = l1, l2, dummy
        while(ptr1 and ptr2):
            if ptr1.val > ptr2.val:
                ptr3.next = ptr2
                ptr2 = ptr2.next
            else:
                ptr3.next = ptr1
                ptr1 = ptr1.next
            ptr3 = ptr3.next
        if ptr1:
            ptr3.next = ptr1
        elif ptr2:
            ptr3.next = ptr2
        return dummy.next
```
### 递归法

* 时间复杂度是O(m+n), 空间复杂度是O(m+n)，平均意义上。最好的情况应该都能达到O(min(m, n))

```python []
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        if l1.val > l2.val:
            l2.next = self.mergeTwoLists(l1, l2.next)
            return l2
        else:
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1
    
```