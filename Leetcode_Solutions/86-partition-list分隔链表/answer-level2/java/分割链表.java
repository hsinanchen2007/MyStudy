**思想就是比较当前结点值和x的大小，然后修改链表，效率比官方题解的效率高**
```
 if (head == null || head.next == null){
            return head;
        }
        ListNode L = new ListNode(-1);
        L.next = head;
        ListNode r = L;
        ListNode p = head;
        ListNode pre = L;
        while (p != null){
            if (p.val < x){
                if (r != pre){
                    pre.next = p.next;
                    p.next = r.next;
                    r.next = p;
                    r = p;
                    p = pre.next;
                }else {//表示包括当前的结点都是小于x的
                    p = p.next;
                    pre = pre.next;
                    r = r.next;
                }
            }else {
                p = p.next;
                pre = pre.next;
            }
        }
        return L.next;
```

