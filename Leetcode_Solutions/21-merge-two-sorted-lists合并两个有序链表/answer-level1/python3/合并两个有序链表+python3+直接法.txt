### 直接法

类似于官解的迭代，以l1为基础逐步插入l2中的元素。代码如下：

```
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 and l2 and l1.val >l2.val or (not l1 and l2):
            l1,l2 = l2,l1
        head = l1
        if not l1 and not l2:
            return None
        while l1.next and l2:
            if l1.next.val<l2.val:
                l1=l1.next
            else:
                p = ListNode(l2.val)
                p.next=l1.next
                l1.next = p
                l2 = l2.next
        if l1 and not l1.next:
            l1.next = l2
        return head
```
#### 复杂度分析
__时间复杂度：__ O(n+m)，每个元素只访问一次

__空间复杂度：__ O(l), 只用到辅助变量