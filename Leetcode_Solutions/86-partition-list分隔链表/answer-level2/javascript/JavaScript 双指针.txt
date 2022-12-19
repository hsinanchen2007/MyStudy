```
    var partition = function(head, x) {
        if (!head || !head.next)
            return head; // 边界处理
        let newhead = new ListNode(null);
        newhead.next = head; // 新增一个头节点
        let q = newhead,
            p,
            flag = true; // 记录第一个大于等于x的节点
        while (q.next) {
            if (flag) { // 如果没找到大于等于x的节点，寻找该节点p
                if (q.next.val >= x) {
                    p = q;
                    flag = false;
                }
                q = q.next;
            } else { // 否则遍历寻找小于x的节点插入p之后，
                if (q.next.val < x) { 
                    let s = q.next; // 删除节点s
                    q.next = s.next; // 删除节点s到p之后
                    s.next = p.next;
                    p.next = s;
                    p = s;  // p更新指向新插入的节点
                } else
                    q = q.next;
            }
        }
        return newhead.next;
    };
```
