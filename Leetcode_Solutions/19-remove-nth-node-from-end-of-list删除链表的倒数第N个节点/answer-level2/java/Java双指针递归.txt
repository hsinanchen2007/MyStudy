- remove方法最终返回的是原链表长度-1
- 使用pre记录上一节点，backIndex记录当前递归返回到了倒数第几个数
- 当倒数记录数等于要删除的数时（n==backIndex），丢弃要删除的节点(pre.next = pre.next.next)
- **特殊情况**  当传入的n大于链表的长度-1时，remove递归不能删除头节点，需要在返回时再做判断：如果传入的**n>链表长度-1**，删除头节点再返回，否则直接返回

```
public ListNode removeNthFromEnd(ListNode head, int n) {
    if (head == null) {
        return null;
    }
    //删除索引数大于总长度-1时，默认删除头节点
    //索引下标最大值=链表长度-1
    return remove(head, head.next, n, 0) < n  ? head.next : head;
}

//返回链表总长度-1
private int remove(ListNode pre, ListNode head, int n, int backIndex) {
    if (head == null) {
        return backIndex;
    }
    backIndex = 1 + remove(head, head.next, n, backIndex);
    if (backIndex == n) {
        // 丢弃节点
        pre.next = pre.next.next;
    }
    return backIndex;
}
```
