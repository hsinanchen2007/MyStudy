```java
    public static ListNode partition(ListNode head, int x) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode temp = head;
        ListNode dummyLess = new ListNode(0);
        ListNode d1 = dummyLess;
        ListNode dummyGreat = new ListNode(0);
        ListNode d2 = dummyGreat;
        while (temp != null) {
            int val = temp.val;
            if (val < x) {
                dummyLess.next = temp;
                dummyLess = dummyLess.next;
            } else {
                dummyGreat.next = temp;
                dummyGreat = dummyGreat.next;
            }
            temp = temp.next;
        }
        dummyLess.next = d2.next;
        dummyGreat.next = null;
        return d1.next;
    }
```
