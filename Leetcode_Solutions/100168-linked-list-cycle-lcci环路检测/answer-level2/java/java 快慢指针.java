```
public ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null) {
            return null;
        }
        ListNode fastPoint = head;
        ListNode slowPoint = head;
        boolean isCycle = false;

        while (fastPoint != null && fastPoint.next != null) {
            slowPoint = slowPoint.next;
            fastPoint = fastPoint.next.next;
            if (slowPoint == fastPoint) {
                isCycle = true;
                break;
            }
        }

        if (isCycle) {
            slowPoint = head;
            while (slowPoint != fastPoint) {
                slowPoint = slowPoint.next;
                fastPoint = fastPoint.next;
            }
            return fastPoint;

        }
        return null;

    }
}
```
