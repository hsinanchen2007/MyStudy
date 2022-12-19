```
/**
 * 借助哑节点，简化操作.
 * 时间复杂度：O(n)，空间复杂度：O(1)
 * 
 * @param head
 * @param val
 * @return
 */
public ListNode deleteNode(ListNode head, int val) {
    // 空链
    if (head == null) {
        return head;
    }

    // 哑节点
    ListNode dummy = new ListNode(-1);
    dummy.next = head;

    ListNode p = dummy;
    while (p.next != null) {
        // 找到节点，删除节点
        if (p.next.val == val) {
            p.next = p.next.next;
        } else {
            // 找不到，则指针往后移
            p = p.next;
        }
    }
    
    return dummy.next;
}
```
