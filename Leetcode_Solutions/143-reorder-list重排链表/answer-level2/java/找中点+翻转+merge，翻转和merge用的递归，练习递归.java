只击败了65%的java，仅供练习递归写法

````
class Solution {
    public void reorderList(ListNode head) {
        //1.找中点 2.断开链表，把中点后面的给翻转了 3.合并两条链表
        if (head == null || head.next == null)
            return;
        ListNode slow = head;
        ListNode fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        //切断
        ListNode needReversed = slow.next;
        slow.next = null;
        ListNode newHead = reverse(needReversed);
        //合并newhead和head
        ListNode cur = head;
        head.next = merge(cur.next, newHead, true);
    }

    public ListNode merge(ListNode node1, ListNode node2, boolean insertNode2) {
        if (node1 == null) return node2;
        if (node2 == null) return node1;
        if (insertNode2) {
            node2.next = merge(node1,node2.next,false);
            return node2;
        }else{
            node1.next = merge(node1.next,node2,true);
            return node1;
        }
    }

    public ListNode reverse(ListNode head) {
        if (head == null)
            return null;
        if (head.next == null)
            return head;
        ListNode cur = head;
        ListNode next = cur.next;
        ListNode newHead = reverse(next);
        cur.next = next.next;
        next.next = cur;
        return newHead;
    }
}
````