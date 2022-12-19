
public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
        int n = lists.length;
        while (n > 1) {
            int index = 0;
            for (int i = 0; i < n;) {
                if (i < n-1) {
                    ListNode cur = merge(lists[i], lists[i+1]);
                    lists[index++] = cur;
                } else {
                    lists[index++] = lists[i];
                }
                i += 2;
            }
            n = index;
        }
        return lists[0];
    }
    private ListNode merge(ListNode l1, ListNode l2) {
        ListNode tmp = new ListNode(0);
        ListNode pre = tmp;
        while (l1 != null && l2 != null) {
            if (l1.val > l2.val) {
                pre.next = l2;
                pre = pre.next;
                l2 = l2.next;
            } else {
                pre.next = l1;
                pre = pre.next;
                l1 = l1.next;
            }
        }
        if (l1 != null) {
            pre.next = l1;
        } else {
            pre.next = l2;
        }
        return tmp.next;
    }