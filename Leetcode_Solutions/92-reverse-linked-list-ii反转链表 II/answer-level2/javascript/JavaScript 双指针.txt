```
var reverseBetween = function(head, m, n) {
        if (!head || !head.next)
            return head; // 边界处理
        let newhead = new ListNode(null);
        newhead.next = head; // 新增一个头节点
        let i = 0,
            s, // s获取删除的节点
            q,  // q 指向要反转位置m的前驱节点
            p = newhead; // p遍历链表
        while (i++ < n) { 
            if (i < m) 
                p = p.next;
            else if (i == m) { // 找到m的前驱节点q
                q = p;
                s = p.next;
                p.next = p.next.next;
                s.next = q.next;
                q.next = s;
                p = p.next; // 将p指向第一个反转后的节点 即m的位置节点
            } else { // 循环删除p的后继节点赋值给s，并将s通过头插法插入q之后，p指向不变
                s = p.next;
                p.next = p.next.next;
                s.next = q.next;
                q.next = s;
            }
        }
        return newhead.next;
    };
```
