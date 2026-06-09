### 解题思路
翻转k链表的函数单写，返回翻转后的头指针。
记录k链表的前一个指针，以及k链表的开始的指针。
### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null){
            return head;
        }
        // 每计数k个节点，就开始倒序
        int i = 0;

        // 用来继续k个节点的尾结点，用来连接下个k个节点
        ListNode node = new ListNode(0);
        node.next = head;

        // k个节点的前面的节点
        ListNode prev = node;
        // k个节点的第一个节点
        ListNode start = node.next;
        // k个节点的当前节点
        ListNode cur = node.next;


        while (cur != null){
            i ++;

            if (i == k){
                ListNode temp = cur.next;
                cur.next = null;
                prev.next = reverse(start);
                start.next = temp;

                i = 0;
                prev = start;
                start = temp;
                cur = temp;
            } else {
                cur = cur.next;
            }

        }

        return node.next;
    }

    public static ListNode reverse(ListNode listNode) {
        ListNode cur = listNode;
        ListNode next = cur.next;
        cur.next = null;
        while (cur != null && next != null) {
            ListNode temp = next.next;
            next.next = cur;
            cur = next;
            next = temp;
        }
        return cur;
    }
}

```