主要思路为：设置 slow 和 fast 两个指针，slow 每次后移一位，fast 每次后移两位，并在指针移动的时候完成链表的反转。

由于是反转前半部分，因此反转后会将链表一分为二，并且是以 slow 和 pre 为头节点的链表。

如：
链表为 1 -> 2 -> 2 -> 1 时

反转后的链表为：
2 -> 1， 此时 pre 指针为链表的头节点
2 -> 1， 此时 slow 指针为链表的头节点

此时，直接比较即可。

又如：
链表为 1 -> 2 -> 3 -> 2 -> 1 时

反转后的链表为：
2 -> 1， 此时 pre 指针为链表的头节点
3 -> 2 -> 1， 此时 slow 指针为链表的头节点

slow 多出一位，因此需要后移动一位，再比较。



```
class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next == null)
            return true;
        ListNode slow = head, fast = head.next, pre = null;
        if(fast.next == null)
            return slow.val == fast.val;
        while(fast != null){
            ListNode node = slow;
            slow = slow.next;
            node.next = pre;
            pre = node;
            if(fast.next != null)
                fast = fast.next.next;
            else
                break;
        }
        if(fast == null)
            slow = slow.next;
        while(pre != null){
            if(pre.val != slow.val)
                return false;
            slow = slow.next;
            pre = pre.next;
        }
        return true;
    }
}
```
