### 解题思路
首先利用快慢指针找到中间的节点，与此同时也将前半段进行反转，
会出现两种情况，一是fast指向null，这个时候链表的长度为偶数，slow指向的后半段链表的开头；
二是fast.next指向null，这个时候链表的长度为奇数，slow指向中间的位置，所以要往后移动一个；
而不管怎么样newHead都是指向前半段反转之后的头节点；接着就是进行比较。

### 代码

```java

public boolean isPalindrome(ListNode head) {
    if (head == null || head.next == null)
        return true;
    ListNode fast = head, slow = head, next = head.next, newHead = null;
    while (fast != null && fast.next != null) {
        fast = fast.next.next;
        slow.next = newHead;
        newHead = slow;
        slow = next;
        next = next.next;
    }
    if (fast != null)   slow = slow.next;
    while (slow != null) {
        if (newHead.val != slow.val)    return false;
        newHead = newHead.next;
        slow = slow.next;
    }
    return true;
}
```