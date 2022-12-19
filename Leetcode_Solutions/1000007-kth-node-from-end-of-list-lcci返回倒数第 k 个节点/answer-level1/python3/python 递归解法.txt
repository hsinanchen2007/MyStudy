## 思路
全局变量+递归，一路遍历到链表尾部，退栈的时候k-1，当k等于0的时候就是要找的节点。

```python3

## 递归解法
class Solution:
    def kthToLast(self, head: ListNode, k: int) -> int:
        self.k = k
        self.res = 0
        
        def kBack(head):
            if not head:
                return
            kBack(head.next)
            self.k -= 1
            if self.k == 0:
                self.res = head.val

         kBack(head)
          
        return self.res
```
