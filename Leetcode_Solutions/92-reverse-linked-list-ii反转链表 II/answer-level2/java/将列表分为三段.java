>执行用时 :0 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :34.5 MB, 在所有 java 提交中击败了80.15%的用户
 
#  

# 代码：

```
    /**
     * 迭代
     *
     * 分为三段：反转段的前部分A，反转段B，反转段后部分C
     * 返回结果为：A + 反转后的B（B'）+ C
     *
     * 反转时：
     * next = cur.next
     * cur.next = pre
     * pre = cur
     * cur = next
     */
    public ListNode reverseList(ListNode head, int m, int n) {
        ListNode preHead = new ListNode(-1); // 假设的新列表的头

        preHead.next = head;

        ListNode pointer = preHead; // 用于遍历，不断向前推进

        for (int i = 1; i < m; i++) {
            pointer = pointer.next;
        }
        // 此时A段结束，A.tail=pointer

        // 需要反转的段，B段开始
        ListNode cur = pointer.next; // 反转段的head
        ListNode pre = null, next = null;
        for (int i = m ; i <=n ; i++) {
            next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }
        // 这时的next是C段的开始,C.head = next

        // 将反转后的列表整合到需要返回的列表中去
        // 即 A + B' + C

        // B.head = pointer.next
        // B'.tail = B.head
        // B'.tail.next = C.head = next
        pointer.next.next = next; // 将反转起点（pointer.next）的next指向反转段后面的部分
        // A.tail = pointer
        // A.tail.next = B'.head = pre
        pointer.next = pre; // 将反转段前一个节点的next指向反转后的头

        return preHead.next;
    }

```
