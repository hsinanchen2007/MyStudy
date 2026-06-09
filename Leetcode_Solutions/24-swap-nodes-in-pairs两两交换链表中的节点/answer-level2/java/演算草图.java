![leetcode24.jpeg](https://pic.leetcode-cn.com/55e220335a9c00002a9c3767e720c008693e8499415bd1d7ead0986a25b32b24-leetcode24.jpeg)

```
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode pp = dummy;
        if (head == null || head.next == null) return head;
        ListNode pre = head;
        ListNode cur = head.next;
        
        while( cur != null ) {
            ListNode next = cur.next;
            // 交换
            cur.next = pre;
            pre.next = next;
            pp.next = cur;

            if(next == null) {
                return dummy.next;
            } else {
                // 右移动2位
                pp = pre; //注意不是 pp = cur !!!
                pre = next;
                cur = next.next;
            }
            
        }
        return dummy.next;
    }
}
```
