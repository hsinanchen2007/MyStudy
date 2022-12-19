python的递归解法思路：从尾节点开始往前遍历（递归），如果当前节点的下一节点是第N个节点时，删除下一节点（将当前节点的下一个节点指向下一个节点的下一个节点）。

```
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if head.next == None: #链表只有一个元素时，直接返回
            return None
        newhead = ListNode(1)  #新定义一个头
        newhead.next = head
        self.count = 0        #用于记录深度
        self.helper(newhead,n) #递归
        return newhead.next   #返回头的下一个节点
    def helper(self,node,n):
        if node == None:
            return 
        self.helper(node.next,n)
        self.count += 1
        if self.count == n+1:         #如果当前节点的下一个节点是要删除的对象，那么将当前节点的下一个节点指向下一个节点的下一个节点
            node.next = node.next.next
```

