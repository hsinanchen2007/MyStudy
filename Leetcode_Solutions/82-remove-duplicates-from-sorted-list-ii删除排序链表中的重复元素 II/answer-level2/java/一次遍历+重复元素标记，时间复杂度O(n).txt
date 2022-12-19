# 思路
1. 考虑到原头指针 head 可能为重复元素而被删除的情况，添加虚拟头结点 dummy;
2. 遍历链表，定义2个指针，分别指向当前 p 、前一个 q ,后一个的话就是 p.next 不用特别定义；
3. 考虑到重复元素都要被删除的情况，添加布尔值 isDuplicate ，标记重复元素，在出现后一个值与当前值不同的情况下，判断当前元素是否被标记，如果标记了，则利用记录的前一个指针 q 将其删除，继续遍历;
4. 注意一些细节上（如尾部）的处理即可。

# 代码
```
public ListNode deleteDuplicates(ListNode head) {
    ListNode dummy = new ListNode(0);
    dummy.next = head;
    ListNode p = head, q = dummy;
    ListNode del = new ListNode(0);
    boolean isDuplicate = false;
    while (p != null) {
        if (p.next != null && p.next.val == p.val) {
            isDuplicate = true;
            // 利用del进行垃圾处理
            del = p.next;
            p.next = p.next.next;
            del = null;
        } else {
            p = p.next;
            if (isDuplicate) {
                // 此时删除当前q.next，q不需要动
                del = q.next;
                q.next = p;
                del.next = null;
                isDuplicate = false;
            } else {
                // 此时p和q 都要前进1
                q = q.next;
            }
        }
    }
    return dummy.next;
}
```
# 总结
时间复杂度O(n),空间复杂度O(1).
