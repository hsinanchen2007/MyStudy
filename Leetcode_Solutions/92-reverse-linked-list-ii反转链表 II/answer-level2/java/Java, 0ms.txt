

```
public ListNode reverseBetween(ListNode head, int m, int n) {
        if(head == null)
            return null;
        ListNode preHead = new ListNode(0);
        preHead.next = head;
        ListNode p = preHead,q = head,r = head.next;
        int i = 1;
        while(i < m)
        {
            p = p.next;
            q = q.next;
            r = r.next;
            i++;
        }

        ListNode lastR = q;
        while(i < n)
        {
            p.next = r;
            q.next = r.next;
            r.next = lastR;
            lastR = r;
            
            r = q.next;
            i++;
        }
        
        return preHead.next;
    }
```
    