
    var deleteDuplicates = function(head) {
        if (!head || !head.next)
            return head; // 空链表和只有一个节点的链表
        let newhead = new ListNode(null);
        newhead.next = head; // 新增一个头节点
        let p = newhead, // 双指针 p，q   p指向要删除节点部分第一个节点的前驱节点
            q = p.next, // q指向要删除节点部分的最后一个节点
            flag = false; // flag 是否检测到重复数据
        while (q.next) {  // 循环
            if (q.val == q.next.val) { // 判断是否重复
                q = q.next;
                flag = true;
                if (!q.next) { // 如果为尾节点，p指向null
                    p.next = q.next;
                    break;
                }
            } else if (flag) { // 不重复，是否要删除
                p.next = q.next;  // 执行删除
                q = p.next;
                flag = false;
            } else { // 否则 p后移一位 ，q指向p后继节点
                p = p.next;
                q = p.next;
            }
        }
        return newhead.next;
    };