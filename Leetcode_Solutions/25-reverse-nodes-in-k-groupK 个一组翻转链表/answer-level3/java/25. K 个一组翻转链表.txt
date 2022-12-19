
![图片来源：https://leetcode-cn.com/problems/reverse-nodes-in-k-group/solution/tu-jie-kge-yi-zu-fan-zhuan-lian-biao-by-user7208t/](https://pic.leetcode-cn.com/9084aacf6e8a38e4bd97dd5e66e3ed4f2a0ea92f673c14bc4bc22eb9a292e8eb.jpg)

- 图片来源：https://leetcode-cn.com/problems/reverse-nodes-in-k-group/solution/tu-jie-kge-yi-zu-fan-zhuan-lian-biao-by-user7208t/

**翻转：**

![IMG_1903](https://pic.leetcode-cn.com/a3a22d72ede6cfd07d18717b357f7d764a51999907a94934cd26ad02bec54fb5.jpg)

### 思路

- 标签：`指针`
- 不新建链表：利用指向链表的引用，即「指针」。在不新建链表的前提下操作原链表
- 待翻转链表：pre、end，未翻转列表：next，已翻转列表：end、start
- 截取链表：start 在前，end 在后，end 指向 null，start 即为截取链表
- 翻转：依次将节点放在 pre 前，使用 pre 存放翻转后的链表
- 时间复杂度：O(n)
- 空间复杂度：O(1)

### 代码

```Java []
// Java
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;
        ListNode pre = dummyHead;
        ListNode end = dummyHead;

        while (end.next != null) {
            for (int i = 0; i < k && end != null; i++) // 如果 end == null，end.next 将报错
                end = end.next;
            if (end == null)
                break;
            ListNode start = pre.next;
            ListNode next = end.next;
            end.next = null;
            pre.next = reverse(start);
            start.next = next;
            pre = start;
            end = pre;
        }
        return dummyHead.next;
    }

    private ListNode reverse(ListNode head) {
        ListNode pre = null;
        ListNode curr = head;
        while (curr != null) {
            ListNode next = curr.next;
            curr.next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
}
```

### 参考

- https://leetcode-cn.com/problems/reverse-nodes-in-k-group/solution/tu-jie-kge-yi-zu-fan-zhuan-lian-biao-by-user7208t/