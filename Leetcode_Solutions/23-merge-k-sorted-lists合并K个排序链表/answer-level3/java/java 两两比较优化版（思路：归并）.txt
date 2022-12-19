### 解题思路
此处撰写解题思路

### 代码

```java

/**
 * @Author : josan
 * @Date : 2020/2/6 20:52
 * @Package : leetcode.study.group002.ex0023
 * @ProjectName: pom-parent
 * @Description:
 */
public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }

        for (int i = 0; i < lists.length; ++i) {
            ListNode dumpHead = new ListNode(-1);
            dumpHead.next = lists[i];
            lists[i] = dumpHead;
        }

        return mergeKListsInnerDivAndConq(lists, 0, lists.length).next;
    }

    private ListNode mergeKListsInnerDivAndConq(ListNode[] lists, int st, int ed) {
        if (ed - st == 1) {
            return lists[st];
        }

        int mid = st + (ed - st) / 2;

        ListNode left = mergeKListsInnerDivAndConq(lists, st, mid);
        ListNode right = mergeKListsInnerDivAndConq(lists, mid, ed);
        return merge2Lists(left, right);
    }


    public ListNode mergeKListsOrigin(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }

        for (int i = 0; i < lists.length; ++i) {
            ListNode dumpHead = new ListNode(-1);
            dumpHead.next = lists[i];
            lists[i] = dumpHead;
        }

        return mergeKListsInner(lists);
    }

    private ListNode mergeKListsInner(ListNode[] lists) {
        ListNode head = lists[0];
        for (int i = 1; i < lists.length; i++) {
            lists[0] = merge2Lists(lists[0], lists[i]);
        }
        return head.next;
    }

    private ListNode merge2Lists(ListNode left, ListNode right) {
        ListNode head = left;
        ListNode cur = head;
        ListNode p = left.next;
        ListNode q = right.next;
        while (p != null && q != null) {
            if (p.val < q.val) {
                cur.next = p;
                cur = p;
                p = p.next;
            } else {
                cur.next = q;
                cur = q;
                q = q.next;
            }
        }

        if (p != null) {
            cur.next = p;
        }
        if (q != null) {
            cur.next = q;
        }
        return head;
    }
}

```