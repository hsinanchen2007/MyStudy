解法一：通过LinkedHashSet存放链表元素去重，效率较高
```
public ListNode removeDuplicateNodes(ListNode head) {

        LinkedHashSet<Integer> vals = new LinkedHashSet<>();

        ListNode cur = head;
        while (cur != null) {
            vals.add(cur.val);
            cur = cur.next;
        }

        ListNode dummyHead = new ListNode(0);
        ListNode p = dummyHead;
        for (int val : vals) {
            p.next = new ListNode(val);
            p = p.next;
        }
            
        return dummyHead.next;
    }
```
解法二：通过两层循环去重，效率较低
```
public ListNode removeDuplicateNodes(ListNode head) {

        ListNode cur = head;
        ListNode p = null;
        while(cur != null) {
            p = cur;
            while(p.next != null) {
                if(cur.val == p.next.val) {
                    p.next = p.next.next;
                } else {
                    p = p.next;
                }
            }
            cur = cur.next;
            
        }
        return head;
    }
```

