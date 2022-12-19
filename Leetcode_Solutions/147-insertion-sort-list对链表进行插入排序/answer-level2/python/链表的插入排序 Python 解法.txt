# 思路

题目描述里的动图非常清楚地展示了对链表进行插入排序的整个过程：

1. 每次取出未排序链表的第一个节点`cur`（在动图里以红框显示） 
2. 从链表头遍历已排序好的链表（在动图里以黑框显示），把`cur`插入到正确的位置
3. 重复前两步

# 代码实现
```
class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        
        dummy = ListNode(-1)
        dummy.next = head
        pre = head #pre始终指着排序好链表的最后一个节点
        cur = head.next #cur始终指着未排序链表的第一个节点
        while cur:
            tail = cur.next
            pre.next = tail  #把cur这个节点拿出来
            
            p = dummy
            while p.next and p.next.val < cur.val: #找到插入的位置
                p = p.next
                
            cur.next = p.next #把cur插入到p和p.next之间
            p.next = cur
            cur = tail
            
            if p == pre:#如果刚插入到了已排序链表的末尾
                pre = pre.next #那么就更新pre
        return dummy.next
```

# 复杂度分析

时间复杂度：$O(N^2)$, 链表中的$N$个节点，都需要用$O(N)$的时间查找正确的插入位置

空间复杂度：$O(1)$