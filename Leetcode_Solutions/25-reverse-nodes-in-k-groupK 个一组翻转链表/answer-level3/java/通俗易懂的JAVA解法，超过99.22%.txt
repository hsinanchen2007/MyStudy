```
public ListNode reverseKGroup(ListNode head, int k) {
        int l = k;
        if (head == null) {
            return null;
        }
        ListNode tail = head;
        // 遍历到第k个节点
        while (l > 1) {
            tail = tail.next;
            l--;
            // 如果已经到达链表末尾，说明不够k个节点，此时不翻转，直接返回
            if (tail == null) {
                return head;
            }
        }
        ListNode nextKHead = tail.next;
        // 对此K个节点翻转
        reverse(head, tail);
        // 翻转后原来头结点变成尾节点，连接下一组
        head.next = reverseKGroup(nextKHead, k);
        return tail;
    }

    /**
     * 对一段链表进行翻转
     * @param start 头结点
     * @param end 尾节点
     * @return
     */
    public ListNode reverse(ListNode start, ListNode end) {
        ListNode dummy = new ListNode(0);
        dummy.next = start;
        ListNode pre = dummy, cur = start;
        while (cur != end) {
            ListNode next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }
        cur.next = pre;
        return end;
    }
```
