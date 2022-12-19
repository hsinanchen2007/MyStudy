- 先遍历求得链表总长度count，同时将链表首尾相连；
- 再找到原链表的倒数第k+1个节点，该节点的next就是新链表的头结点。
```java
public ListNode rotateRight(ListNode head, int k) {
	if (head == null || head.next == null || k == 0) return head;
    
    int count = 1; // 用来统计链表总结点数
    ListNode tmp = head;
    while (tmp.next != null) {
        count++;
        tmp = tmp.next;
    }
    k %= count;
    // 当k为0时，不需要旋转，
    if (k == 0) return head;
    
    // 不满足上述条件，必将进行旋转，所以先将首尾相连
    tmp.next = head;
    // 现在只需要找到倒数第k+1个节点
    for (int i = 0; i < count - k; i++) {
        tmp = tmp.next;
    }
    ListNode newHead = tmp.next;
    tmp.next = null;
    return newHead; 
}
```