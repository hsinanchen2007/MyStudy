```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void reorderList(ListNode head) {
        if (head == null || head.next == null || head.next.next == null)
            return;
        ListNode res = head;
        //1、找中间节点
        ListNode middle = middleNode(head);
        //2、反转后半部分节点
        ListNode revertHead = reverse(middle);
        //3、合并，找到middle为止,当前两部分head ---->middle revertHead --- >middle
        ListNode first = head.next;
        ListNode second = revertHead;
        //一旦遇见middle说明遍历结束了，单独处理下middle即可
        while (first != middle && second != middle) {
            head.next = second;
            second = second.next;
            head = head.next;
            head.next = first;
            first = first.next;
            head = head.next;
        }
        //当第一个指向middle或者第二个指向middle
        if (first == middle && second == middle) {
            head.next = middle;

        } else {
            head.next = second;
            head = head.next;
            head.next = middle;
        }
        head = res;
    }

    //寻找中间节点
    public ListNode middleNode(ListNode node) {
        if (node == null || node.next == null)
            return node;
        ListNode slow = node;
        ListNode fast = node.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return fast == null ? slow : slow.next;
    }

    //反转链表
    public ListNode reverse(ListNode head) {
        if (head.next == null)
            return head;
        ListNode last = reverse(head.next);
        head.next.next = head;
        head.next = null;
        return last;
    }
}
```
