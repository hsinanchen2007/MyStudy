三个步骤：
1. 找中间结点
2. 中间节点及后面翻转 得到新链表B。无需区别链表长度是奇数or偶数
3. 原链表与B比较结点值，得到不同就返回false

```
class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null) return true;
        if (head.next == null) return true;
        //找中间结点
        ListNode mid = midNode(head);
        //中间结点及后面翻转
        ListNode B = reverse(mid);
        //比较
        ListNode A = head;
        while (B != null) {
            if (A.val != B.val) { //比较结点相同 还是值相同
                return false;
                // break;
            }
            A = A.next;
            B = B.next;
        }
        return true;
    }
    
    //找中间结点
    public ListNode midNode(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }
    
    //翻转
    public ListNode reverse(ListNode head) {
        ListNode prev = null;
        ListNode cur = head;
        ListNode pnext = cur.next;
        ListNode newHead = null;
        while (cur != null) {
            pnext = cur.next;
            if (pnext == null) {
                newHead = cur;
            }
            cur.next = prev;
            prev = cur;
            cur = pnext;
        }
       return newHead; 
    }
}
```