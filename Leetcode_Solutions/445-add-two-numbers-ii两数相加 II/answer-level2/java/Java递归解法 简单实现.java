Java 2ms，时间100%，空间99%
解法：先计算两个链表的长度，较短的链表高位补0，使两个链表长度一致。然后递归计算结果，将所得结果保存到其中一个链表中，对最高位进位进行判断，返回链表头即可。代码逻辑较简单。
```
public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int len1 = 0, len2 = 0;
        ListNode cur = l1;
        while (cur != null){
            cur = cur.next;
            len1++;
        }
        cur = l2;
        while (cur != null) {
            cur = cur.next;
            len2++;
        }
        while (len2 < len1) {
            ListNode tmp = new ListNode(0);
            tmp.next = l2;
            l2 = tmp;
            len2++;
        }
        while (len1 < len2) {
            ListNode tmp = new ListNode(0);
            tmp.next = l1;
            l1 = tmp;
            len1++;
        }
        if (addNumberHelper(l1, l2) == 1) {
            ListNode tmp = new ListNode(1);
            tmp.next = l1;
            l1 = tmp;
        }
        return l1;
    }

    private int addNumberHelper(ListNode l1, ListNode l2) {
        if (l1 != null){
            l1.val = l1.val + l2.val + addNumberHelper(l1.next, l2.next);
            if (l1.val > 9) {
                l1.val = l1.val % 10;
                return 1;
            }
        }
        return 0;
    }
```
