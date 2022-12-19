从归并排序的实际实现来说，第一轮是先把长度为1的两个链表合并，第二轮合并长度为2的两个链表，依次作为模拟过程，用代码实现即可。

处理链表问题注意该断开的地方断开。

```
    public ListNode sortList(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode end = findEnd(head);
        return sortList(head, end);
    }

    int n = 1;

    private ListNode sortList(ListNode head, ListNode end) {
        if (head == null || head == end) {
            return head;
        }
        ListNode fakeH = new ListNode(0);
        fakeH.next = head;

        for (int subLen = 1; subLen < n; subLen *= 2) {//两个子串的长度
            ListNode prev = fakeH;
            ListNode start1 = fakeH.next;
            while (start1 != null) {
                ListNode start2 = getList(start1, subLen);//[start1,start2)长度为i，start2可能为null

                ListNode end2 = getList(start2, subLen);//如果end2为null
                //对这两个链表排序
                ListNode[] resTmp = mergeList(start1, start2);//最后一个节点需要链接到tmp

                prev.next = resTmp[0];

                prev = resTmp[1];//上一轮结束
                start1 = end2;//下一段开始
            }
        }
        return fakeH.next;
    }

    /**
     * 从before开始取i个
     *
     * @param before
     * @param step
     * @return 下一段的起点
     */
    private ListNode getList(ListNode before, int step) {
        //找到从起点开始的第n-1个点，返回其后的节点,其后置位null（断开）
        if (before == null) {
            return null;
        }
        for (int i = 1; i < step; i++) {
            if (before.next == null) {
                break;
            } else {
                before = before.next;
            }
        }
        ListNode res = before.next;
        before.next = null;
        return res;
    }

    /**
     * 合并h1、h2
     *
     * @param h1
     * @param h2
     * @return 排序后的头结点、尾节点
     */
    private ListNode[] mergeList(ListNode h1, ListNode h2) {
        ListNode fakeH = new ListNode(0);
        ListNode before = fakeH;
        while (h1 != null && h2 != null) {
            if (h1.val <= h2.val) {
                before.next = h1;
                h1 = h1.next;
            } else {
                before.next = h2;
                h2 = h2.next;
            }
            before = before.next;
        }
        if (h1 != null) {
            before.next = h1;
        } else if (h2 != null) {
            before.next = h2;
        }
        while (before.next!=null){
            before=before.next;
        }

        ListNode[] res=new ListNode[2];
        res[0]=fakeH.next;
        res[1]=before;
        return res;
    }

    private ListNode findEnd(ListNode head) {//找尾节点的过程中计数总结点数
        ListNode cur = head;
        while (cur.next != null) {
            n++;
            cur = cur.next;
        }
        return cur;
    }
```
