```
public ListNode detectCycle(ListNode head) {
        //先用快慢指针判断是否是环形
        ListNode slow = head;
        ListNode fast = head;
        boolean isCycle = false;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                isCycle = true;
                break;
            }
        }
        if (isCycle) {
            //慢指针不动，利用快指针找出环的大小
            int cycleSize = 1;
            fast = fast.next;
            while (!(slow == fast)) {
                fast = fast.next;
                cycleSize++;
            }
            //根据环的大小，利用双指针找出环形入口，前后指针间隔为环的大小
            ListNode slow1 = head;
            ListNode fast1 = head;
            while (cycleSize - 1 > 0) {
                fast1 = fast1.next;
                cycleSize--;
            }
            //找入口的关键判断条件
            while (!(fast1.next == slow1)) {
                slow1 = slow1.next;
                fast1 = fast1.next;
            }
            return slow1;
        }
        return null;
    }
```