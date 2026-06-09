slow:慢指针每次走一步
fast：快指针每次走两步
将慢指针经过的节点指向前一个节点
当快指针走到链表尽头时，再从慢指针处向前向后对称比较数值
```
public boolean isPalindrome(ListNode head) {
        if (head == null)
            return true;
        ListNode slow = head;
        ListNode fast = slow.next;
        ListNode tmp = null;
        ListNode pre = null;
        boolean flag = false;
        while (fast != null){
            fast = fast.next;
            if (fast == null){
                flag = true;
                break;
            }
            fast = fast.next;
            tmp = slow.next;
            slow.next = pre;
            pre = slow;
            slow = tmp;
        }
        fast = slow.next;
        if (flag){
            slow.next = pre;
            pre = slow;
        }
        while (pre != null){
            if (pre.val != fast.val)
                return false;
            pre = pre.next;
            fast = fast.next;
        }
        return true;
    }
```
