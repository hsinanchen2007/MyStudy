```
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode lowHead = null,lowCur = null,highHead = null,highCur = null;
        ListNode cur = head;
        while (cur != null) {

            // System.out.println(cur.val);

            if (cur.val < x) {
                if (lowHead == null) {
                    lowHead = cur;
                    lowCur = cur;
                } else {
                    lowCur.next = cur;
                    lowCur = cur;
                }
            } else {
                if (highHead == null) {
                    highHead = cur;
                    highCur = cur;
                } else {
                    highCur.next = cur;
                    highCur = cur;
                }
            }
            cur = cur.next;
        }
        
        if (lowHead != null) {
            lowCur.next = highHead;
        } else {
            lowHead = highHead;
        }

        if (highCur != null) {
            highCur.next = null;
        }

        return lowHead;
    }
}
```
