

## 非递归写法
为了方便，设置了虚拟头结点。通过pre和cur两个指针指向元素不断比较。
cur指针可以省略，等效于官方的解法。

```python 
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        dummy_head = ListNode(None)
        dummy_head.next = head

        pre = dummy_head
        cur = head

        while cur:
            if pre and cur.val == pre.val:
                pre.next = cur.next
                cur.next = None
                cur = pre.next
                continue

            pre = cur
            cur = cur.next
        return dummy_head.next
```

## 递归解法
递归函数返回的不重复子链的头结点，在回溯过程中，比较当前节点和子链头结点的`val`是否相同，若相同则保留当前节点（删除子链的头结点）。

```python
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        
        child = self.deleteDuplicates(head.next)
        if child and head.val == child.val:
            head.next = child.next
            child.next = None
            
        return head
        
```
