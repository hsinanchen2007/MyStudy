```java
public static ListNode partition(ListNode head, int x) {
        if(head == null) return null;
        ListNode lowHead = null;
        ListNode highHead = null;
        ListNode lowPre = null;
        ListNode highPre = null;
        ListNode cur = head;
        while (cur!=null){
            if(cur.val<x){
                if(lowHead == null){
                    lowHead = cur;
                }
                if (lowPre!=null)
                    lowPre.next = cur;
                lowPre = cur;
                cur = cur.next;
                lowPre.next = null;//断链
            } else {
                if(highHead == null)
                    highHead = cur;
                if (highPre!=null)
                    highPre.next = cur;
                highPre = cur;
                cur=cur.next;
                highPre.next = null;//断链
            }
        }
        if (lowHead!=null) {
            lowPre.next = highHead;
            return lowHead;
        }
        return highHead;
    }
```
