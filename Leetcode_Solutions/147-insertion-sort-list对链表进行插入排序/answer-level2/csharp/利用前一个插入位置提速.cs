看了下题解，大部分人都提到了利用 Tail 指针进行提速，当这种情况只适用测试用例正好最大的在后面的情况，概率上来说发生的可能性是很小的。其实完全可以利用前一个插入的位置进行提速，即每次先把当前要插入的元素和前一个插入点比较，如果比它大，那么就从这里开始搜索，否则才需要从链表头开始搜索。

```
public ListNode InsertionSortList(ListNode head)
{
    var dummy = new ListNode(0);
    var pre = dummy;

    for (var node = head; node != null;)
    {
        var cur = node;
        node = node.next;

        // 与前一个插入点比较决定从哪里开始搜索
        if (cur.val < pre.val) pre = dummy;

        while (pre.next != null && cur.val > pre.next.val) pre = pre.next;

        cur.next = pre.next;
        pre.next = cur;
    }

    return dummy.next;
}
```

时间复杂度：平均只要搜索半个链表，比简单的从头开始搜索快一倍。
空间复杂度：$O(1)$