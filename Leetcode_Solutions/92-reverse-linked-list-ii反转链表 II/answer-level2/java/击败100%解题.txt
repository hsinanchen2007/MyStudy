**思路：翻转之前记录开始位置**。
定义4个指针，**j指向m的位置；i指向j的前一个位置；**
翻转m到n的链表。翻转完成后。**q这是恰好指向n位置，p指向q.next。**
此时把i的下一个指向q，j的下一个指向p，即可。
```
public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode o = new ListNode(0);
        o.next = head;
        ListNode i = o;
        for (int l = 0; l < m - 1; l++) {
            i = i.next;
        }
        ListNode q = i.next;
        ListNode j = i.next;
        ListNode p = q.next;
        boolean flag = true;
        for (int k = m; k < n && p != null; k++) {
            ListNode t = p.next;
            if (flag) {
                q.next = null;
                flag = false;
            }
            p.next = q;
            q = p;
            p = t;
        }
        i.next = q;
        j.next = p;
        return o.next;
    }
```

