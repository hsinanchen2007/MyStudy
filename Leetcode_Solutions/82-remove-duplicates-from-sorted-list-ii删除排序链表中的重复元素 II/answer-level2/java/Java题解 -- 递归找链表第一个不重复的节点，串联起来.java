1. 从头节点开始，获取第一个不重复的节点，记为newHead
2. 递归调用删除重复元素方法，从newHead.next开始，获取第一个不重复的节点，并赋值给newHead.next
3. 调用至链表末尾，结束
4. 返回newHead，即为删除重复元素之后的链表
```
public ListNode deleteDuplicates(ListNode head) {
    ListNode newHead = getFirst(head);
    if (newHead != null) {
        newHead.next = deleteDuplicates(newHead.next);
    }
    return newHead;
}

// 获取当前链表中第一个不重复的节点
private ListNode getFirst(ListNode head) {
    if (head == null || head.next == null) {
        return head;
    }
    // 开头无重复元素，直接返回
    if (head.val != head.next.val) {
        return head;
    }
    // 开头有重复元素，找到当前重复元素的末尾
    while (head.next != null && head.val == head.next.val) {
        head = head.next;
    }
    // 递归调用，获取子链表的第一个不重复元素
    return getFirst(head.next);
}
```
