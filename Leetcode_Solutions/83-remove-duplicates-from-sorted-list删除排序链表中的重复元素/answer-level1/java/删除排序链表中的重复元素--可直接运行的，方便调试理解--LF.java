```
package ZJM_83_删除排序链表中的重复元素;

public class Main {
    public static void main(String[] args) {
//        1->1->2     1->1->2->3->3
        ListNode l1 = new ListNode(1);
        ListNode l2 = new ListNode(1);
        ListNode l3 = new ListNode(2);

        ListNode m1 = new ListNode(1);
        ListNode m2 = new ListNode(1);
        ListNode m3 = new ListNode(2);
        ListNode m4 = new ListNode(3);
        ListNode m5 = new ListNode(3);

        ListNode n1 = new ListNode(1);
        ListNode n2 = new ListNode(1);
        ListNode n3 = new ListNode(1);

        l1.next = l2;
        l2.next = l3;
        l3.next = null;

        m1.next = m2;
        m2.next = m3;
        m3.next = m4;
        m5.next = null;

        n1.next = n2;
        n2.next = n3;
        n3.next = null;

        Solution solution = new Solution();
        ListNode result1 = solution.deleteDuplicates(l1);

        while (result1 != null) {
            System.out.print(result1.val + " ");
            result1 = result1.next;
        }

        System.out.println();

        ListNode result2 = solution.deleteDuplicates(m1);

        while (result2 != null) {
            System.out.print(result2.val + " ");
            result2 = result2.next;
        }

        System.out.println();

        ListNode result3 = solution.deleteDuplicates(n1);

        while (result3 != null) {
            System.out.print(result3.val + " ");
            result3 = result3.next;
        }
    }
}

/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode result = new ListNode(-1);     //定义一个头节点，并将其next指向head，用来返回结果
        result.next = head;

        while (head!=null&&head.next != null) {
            if (head.next.val == head.val) {
//                head.val = head.next.val;
                head.next = head.next.next;
            }else {
                head = head.next;
            }
        }

        return result.next;
    }
}

/**
 * 当head.next不为空的时候，循环进行，遍历链表
 * 当链表下一节点值等于当前节点值时，
 * 将指向下一节点的指针指向下一节点的下一节点（也就是跳过下一节点）
 * 否则指向下一个
 * 最后返回result.next，也就是head链表
 * 特别要注意，循环条件不仅仅要head.next!=null，同时也要head!=null
 */

```
