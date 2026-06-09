哑节点,也叫哨兵节点,通常它的next指向头节点,会简化链表操作或者减少特殊情况的讨论。
但如果题目非得要求不能创建额外节点呢？
哈哈哈，其实一般不会有这么无理的要求，其实事实是我最开始没想到，所以没有使用哑节点。
下面就介绍一下，无哑节点的迭代实现:
**假设指针p指向最小值较小的递增链的头节点,指针q指向最小值较大的递增链的头节点。
我们要做的工作其实就是，将q链中的所有元素都合并到p上**
详细说明见注释，代码如下：
```python []
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1: return l2
        if not l2: return l1
        if l1.val>l2.val:
            l1,l2 = l2,l1
        p,q = l1,l2
        # 将q链的全部内容合并到p链里
        while q:
            # p链没到最后一个节点
            if p.next:
                # 如果符合条件把q链一个元素插入p链
                if q.val >= p.val and q.val < p.next.val:
                    t = q.next
                    q.next = p.next
                    p.next = q
                    q = t
            # p链到最后一个节点了
            else:
                # q链所有元素插入p链,q链被吸干
                p.next = q
                q = None
            p = p.next
        return l1
```
值得注意的是,虽然没有使用额外节点,但是却修改了初始链表的原始结构。
如果题目明确要求原址修改不得使用额外节点,可以使用这种思路。

