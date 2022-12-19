设置快慢指针，移动速度分别是2和1。当快指针到达链表尾部的时候，慢指针就在正中间（奇数个节点的情况下）或者正中间的左边（偶数个节点的情况下），再将慢指针向后移动一位，反转以慢指针为头的链表，再逐个节点对比是否相等。

```java
public boolean isPalindrome (ListNode head) {
    if (head == null || head.next == null) return true;
    ListNode slow = head;
    ListNode fast = head.next;
    while (fast != null && fast.next != null) {

        slow = slow.next;
        fast = fast.next.next;
    }

    slow = slow.next;
    slow = reverse(slow);

    while (slow != null) {
        if (head.val == slow.val) {
            head = head.next;
            slow = slow.next;
        } else
            return false;
    }
    return true;

}

private ListNode reverse (ListNode head) {
    ListNode newHead = null;
    while (head != null) {
        ListNode nextNode = head.next;
        head.next = newHead;
        newHead = head;
        head = nextNode;
    }
    return newHead;
}
```







