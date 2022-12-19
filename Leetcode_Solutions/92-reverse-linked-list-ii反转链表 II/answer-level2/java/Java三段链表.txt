- 将链表分为三段:1~m为第一段链表preHead,m~n为第二段反转链表reverseNode,n~末尾为第三段链表tailListNode
- 头插法反转reverseNode
- preHead + reverseNode + tailListNode即为结果
**特殊情况:** 当m为1时,preHead为null，需要特殊判空
```
public ListNode reverseBetween(ListNode head, int m, int n) {
    if (head == null || head.next == null || m == n) {
        return head;
    }
    // 链表可根据m,n分为三段链表,如下：
    // 反转链表前的链表preHead、反转链表reverseNode、反转链表后的链表tailListNode
    // 如1->2->3->4->5，2，5的三段链表如下：
    // preHead: 1
    // reverseNode: 2->3->4
    // tailListNode: 5
    ListNode curr = head;

    ListNode preHead = null;// 记录反转前的最后一个节点

    // 获取需要反转的链表段的第一个节点
    for (int i = 1; i < m && curr != null; i++) {
        if (i + 1 == m) {
            preHead = curr;
        }
        curr = curr.next;
    }
    // 反转链表段的第一个虚拟节点
    ListNode reverseNode = new ListNode(-1);
    // tailListNode的第一个节点为反转链表reverseNode反转前的头节点，即
    // 1->2->3->4->5反转链表为2->3->4，反转后4->3->2->5
    // 2(反转前的头节点)的next为5(反转链表后的链表)
    ListNode tailListNode = reverseNode.next;
    for (int i = m - 1; i < n && curr != null; i++) {
        // 反转链表段2->3->4->5为4->3->2->5
        // 头插法
        ListNode curTmp = curr.next;
        ListNode tmp = reverseNode.next;
        reverseNode.next = curr;
        curr.next = tmp;
        curr = curTmp;
        if (i == m - 1) {
            //反转到n个数时记录反转链表的尾节点
            tailListNode = reverseNode.next;
        }
    }
    //curr为在反转链表后不需要反转的链表，curr拼接在反转链表后面
    tailListNode.next = curr;
    if (preHead != null) {
        // m不是从1开始时，存在preHead，拼接第一段链表和反转链表
        preHead.next = reverseNode.next;
        return preHead;
    } else {
        // 从第一个节点开始反转时，preHead为空，直接返回虚拟头节点的下一个节点
        return reverseNode.next;
    }
}
```
