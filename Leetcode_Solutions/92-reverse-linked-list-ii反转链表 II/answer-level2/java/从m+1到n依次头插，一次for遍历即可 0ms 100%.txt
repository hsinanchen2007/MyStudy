pre指向m的前一个结点，从m+1到n依次插入到pre之后即可，只需一次for循环，0ms 100%
```java
public ListNode reverseBetween(ListNode head, int m, int n) {
    if (null == head || null == head.next || m == n) {
        return head;
    }
    // 头结点
    ListNode newHead = new ListNode(0);
    newHead.next = head;
    ListNode pre = newHead, cur = head;
    for (int i = 1; i < n; i++) {
        if (i < m) {
            // cur移到需要反转的起始结点m，pre是前一个结点
            pre = cur;
            cur = cur.next;
        } else {
            // 从m+1到n，依次插入到pre后即可
            ListNode temp = cur.next;
            cur.next = cur.next.next;
            temp.next = pre.next;
            pre.next = temp;
        }
    }
    return newHead.next;
}
```
