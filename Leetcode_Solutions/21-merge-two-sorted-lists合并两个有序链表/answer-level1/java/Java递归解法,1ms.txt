- 执行用时 :1 ms, 在所有 Java 提交中击败了99.77%的用户
- 内存消耗 :35.9 MB, 在所有 Java 提交中击败了87.55%的用户
```Java []
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummyhead = new ListNode(0);
        merge(dummyhead, l1, l2);
        return dummyhead.next;
    }

    /**
     * 合并,递归
     * @param head
     * @param l1
     * @param l2
     * @return
     */
    private static void merge(ListNode head, ListNode l1, ListNode l2) {
        if (l1 != null && l2 != null) {
            //把head.next和l1.next放到下一轮递归
            if (l1.val <= l2.val) {
                head.next = l1;
                ListNode p = l1.next;
                l1.next = null;
                merge(head.next, p, l2);
            } else {
                //把head.next和l2.next放到下一轮递归
                head.next = l2;
                ListNode p = l2.next;
                l2.next = null;
                merge(head.next, l1, p);
            }
        }
        if (l1 == null && l2 == null) ;
        if (l1 == null && l2 != null) {
            //把head.next和l2.next放到下一轮递归
            head.next = l2;
            ListNode p = l2.next;
            l2.next = null;
            merge(head.next, l1, p);

        }
        if (l1 != null && l2 == null) {
            //把head.next和l1.next放到下一轮递归
            head.next = l1;
            ListNode p = l1.next;
            l1.next = null;
            merge(head.next, p, l2);
        }
    }
}
```
