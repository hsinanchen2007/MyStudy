```
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {

        if (l1 == null) {
            return l2;
        } else if (l2 == null) {
            return l1;
        }

        ListNode p1 = l1,p2 = l2;

        ListNode rs = new ListNode(0);
        ListNode rsCur = rs;

        while (true) {
            if (p1 == null) {
                rsCur.next = p2;
                break;
            } else if (p2 == null) {
                rsCur.next = p1;
                break;
            }

            if (p1.val < p2.val) {
                rsCur.next = p1;
                rsCur = rsCur.next;
                p1 = p1.next;
            } else {
                rsCur.next = p2;
                rsCur = rsCur.next;
                p2 = p2.next;
            }
        }
        return rs.next;
    }
}
```
