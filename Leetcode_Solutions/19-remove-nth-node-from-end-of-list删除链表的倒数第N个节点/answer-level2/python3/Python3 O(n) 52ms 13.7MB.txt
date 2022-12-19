语言：Python3
效果：O(n) 52ms 13.7MB
```python []
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        # 添加前置节点（解决各种NoType的问题）
        temp = ListNode(0)
        temp.next = head
        temp1, temp2 = temp, temp
        # 快指针优先运动n个
        for i in range(n):
            temp1 = temp1.next
        # 快慢同时运动直到快指针到达链尾
        while temp1 and temp1.next:
            temp2 = temp2.next
            temp1 = temp1.next
        # 删除节点
        temp2.next = temp2.next.next
        return temp.next
```
