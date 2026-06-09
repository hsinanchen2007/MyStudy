```
public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode newListNode = null;
        ListNode q = l1;
        ListNode p = l2;
        ListNode curr=newListNode;

        while (q != null || p != null) {
            int a, b = 0;
            a = q == null ? 0 : q.val;
            b = p == null ? 0 : p.val;
            if (q != null) {
                if (p != null) {
                    if (a <= b) {
                        if (curr == null){
                            newListNode=new ListNode(a);
                            curr=newListNode;
                        }else {
                            curr.next=new ListNode(a);
                            curr=curr.next;
                        }
                        q = q.next;
                    } else {
                        if (newListNode == null){
                            newListNode=new ListNode(b);
                            curr=newListNode;
                        }else {
                            curr.next=new ListNode(b);
                            curr=curr.next;
                        }
                        p = p.next;
                    }
                } else {
                    if (newListNode == null){
                        newListNode=new ListNode(a);
                        curr=newListNode;
                    }else {
                        curr.next=new ListNode(a);
                        curr=curr.next;
                    }
                    q=q.next;
                }

            } else {
                if (newListNode == null){
                    newListNode=new ListNode(b);
                    curr=newListNode;
                }else {
                    curr.next=new ListNode(b);
                    curr=curr.next;
                }
                p = p.next;
            }

        }

        return newListNode;
    }
```
