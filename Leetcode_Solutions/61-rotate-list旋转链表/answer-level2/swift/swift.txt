1: 判断过滤空链表和只有一个节点的链表

        if head == nil || head?.next == nil {
            return head
        }
2: 统计链表中节点数量，并找到尾节点

        var pre = head
        var count = 1
        while pre?.next != nil {
            pre = pre?.next
            count += 1
        }

3: 首尾相连，以尾节点作为首节点，计算移动步骤并移动首节点

        pre?.next = head
        var step = count - k % count
        while step != 0 {
            step -= 1
            pre = pre?.next
        }

4: 新节点的下一节点为首节点，断开链表

        let newHead = pre?.next
        pre?.next = nil

完整代码如下所示:

        if head == nil || head?.next == nil {
            return head
        }
        var pre = head
        var count = 1
        while pre?.next != nil {
            pre = pre?.next
            count += 1
        }
        // 首尾相连(新首节点为尾部节点)
        pre?.next = head
        var step = count - k % count
        while step != 0 {
            step -= 1
            pre = pre?.next
        }
        let newHead = pre?.next
        pre?.next = nil
        return newHead
