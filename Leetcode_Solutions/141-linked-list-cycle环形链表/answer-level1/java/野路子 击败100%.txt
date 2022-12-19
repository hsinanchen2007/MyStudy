``` java
    public boolean hasCycle(ListNode head) {
        ListNode cur = head;
        while (cur != null && cur.val != Integer.MAX_VALUE) {
            cur.val = Integer.MAX_VALUE;
            cur = cur.next;
        }
        return cur != null;
    }
```
快慢指针追太慢，直接赋特殊值判断即可