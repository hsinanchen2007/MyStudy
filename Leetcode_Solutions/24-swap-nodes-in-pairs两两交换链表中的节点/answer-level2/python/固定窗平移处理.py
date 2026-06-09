链表节点的交换主要有三个步骤：前驱->右节点，右节点->左节点，左节点->后继。
设置x，y分别保存前驱和后继，交换left和right。
```
 def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        pre = ListNode(-1)
        pre.next = head

        if head is None:
            return pre.next
        left = head
        right = head.next
        x = pre     # 保存左节点前驱节点

        while left and right and right.next:
            y = right.next      # 保存右节点后继
            # 交换
            right.next = left   # 右变左
            if x == pre:    # 表头处理
                head = right
                pre.next = head
            else:
                x.next = right  # 前驱处理
            left.next = y   # 左变右
            # 后移，此时left在右，right在左
            x = left
            left = y
            right = y.next

        # 奇数处理
        if right is not None:
            x.next = right
            right.next = left
            left.next = None

        return pre.next
```
