# 思路
- 遍历一次，计算链表总长度
- 将链表不断二分（至只有一个元素），断开，遍历左右两部分->顺序链接

# 代码
```
public ListNode binarySort(ListNode h, int n) {
    // n 为h链表的总节点个数
    ListNode combine = new ListNode(0);
    if (h.next == null) {
        return h;
    }
    
    ListNode left = h, r_pre = h, right = h;
    int l_len = (n + 1) / 2, r_len = n - (n + 1) / 2;
    for (int i = 1; i < l_len; i++) {
        r_pre = r_pre.next;
    }
    right = r_pre.next;
    // 左右断开
    r_pre.next = null;
    // 分别排序
    left = binarySort(left, l_len);
    right = binarySort(right, r_len);

    // 归并左右
    combine.next = left;
    // p指向遍历过程中left的前一个元素
    ListNode p = combine;
    while (left != null && right != null) {
        if (left.val > right.val) {
            r_pre = right;
            right = right.next;
            // q接到p的后面，left的前面
            p.next = r_pre;
            r_pre.next = left;
            p = r_pre;
        } else {
            left = left.next;
            p = p.next;
        }
    }
    // 若left不为空，其实left剩余部分已经在最终合并之后的链表中了，所以不用再考虑；
    // 若right不为空，将right剩余部分接到p的后面
    if (right != null) {
        p.next = right;
    }

    return combine.next;
}
public ListNode sortList(ListNode head) {
    if (head == null || head.next == null) {
        return head;
    }
    ListNode p = head;
    int count = 0;
    while (p != null) {
        count++;
        p = p.next;
    }
    return binarySort(head, count);
}
```

# 总结
- 时间复杂度O(nlogn):遍历一次O(n),归并排序O(nlogn)
- 空间复杂度O(1)