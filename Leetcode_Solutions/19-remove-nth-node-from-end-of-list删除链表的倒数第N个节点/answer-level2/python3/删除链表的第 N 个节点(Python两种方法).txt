### 方法一: 先找出要删除的节点,然后指针指向该节点并删除

### 代码

```python

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:

        dummy = ListNode(0)
        dummy.next = head
        count = 0
        first = head

        while first:
            count += 1
            first = first.next
        
        idx = count - n
        first = dummy
        while idx > 0:
            idx -= 1
            first = first.next
        first.next = first.next.next
        return dummy.next
```

### 方法二: 使用双指针
1. 由于头节点有可能被删除,故设置 pre 指针指向 head
2. 设置快慢指针 前后指针 start, end, 指向 pre. 先让 end 走 n 步, 再将 start 和 end 一起移动.当 end.next 为 None时, 也就是 end 到了尾节点时, start 真好走到待删除节点的前一个节点.
3. 此时 让 start.next = start.next.next, 即可删除 倒数第 n 个节点. 返回 pre.next 即可. 此处不返回 head 是因为 head 可能被删除.
```python
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
       
        pre = ListNode(0)
        pre.next = head
        start = pre
        end = pre

        count = 0
        while count<n:
            start = start.next
            count += 1
        while start.next != None:
            start = start.next
            end = end.next
            
        end.next = end.next.next
        return pre.next
```








```