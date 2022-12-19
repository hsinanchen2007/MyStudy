### 方法一: 用 dict 存储 node
记录下每个看过的 ListNode,若当前 node 在 table 中, 则说明有环, 返回 True, 否则进行到尾部 返回 False

### 代码

```python
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        adict = {}
        cur = head
        while cur:
            if cur in adict:
                return True
            else:
                adict[cur] = 0
                cur = cur.next
        return False
```
### 方法二: 用 快慢指针
若没有环, 快指针必然先到尾部, 返回 false, 若有环, 快慢指针会相等
```python
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        """
        if head == None or head.next == None:
            return False
        slow = head
        fast = head.next
        while slow != fast:
            if fast == None or fast.next == None:
                return False      
            slow = slow.next
            fast = fast.next.next      
        return True
        """
```