```
class Solution {
    public boolean isPalindrome(ListNode head)
    {
        if(head==null || head.next==null)
            return true;
        //快慢指针找到链表的中点
        ListNode slow = head, fast = head;
        while (true)
        {
            slow = slow.next;
            if (fast.next == null || fast.next.next == null)
            {
                break;
            }
            fast = fast.next.next;
        }
        //反转slow及其后面的结点
        ListNode p = slow, q = p.next, r = (q == null ? null : q.next);
        while (true)
        {
            if (p == slow)
            {
                p.next = null;
            }
            if (q == null)
            {
                break;
            }
            q.next = p;
            p = q;
            q = r;
            if (q == null)
            {
                break;
            }
            r = q.next;
        }
        //此时p指向右半部分的头
        while (p != null)
        {
            if (p.val != head.val)
            {
                return false;
            }
            p = p.next;
            head = head.next;
        }
        return true;
    }
}
```

执行用时 :1 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :42.1 MB, 在所有 Java 提交中击败了100.00%的用户
