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
    public ListNode reverseKGroup(ListNode head, int k) {
        if (null == head || k <= 1) return head;
        
        // 声明一个伪结点dummy，避免对头结点进行特别讨论
        ListNode dummy = new ListNode(-1);
        // lastGroupTail用来记录已反转部分的尾结点，初始化为dummy
        // nextGroupHead用来记录未反转部分的头结点，初始化为head
        ListNode lastGroupTail = dummy, nextGroupHead = head;
        lastGroupTail.next = nextGroupHead;
        int cnt = 0;
        ListNode cur = head;
        while (cur != null) {
            cnt++;
            // 对待反转部分进行反转，k个元素一组
            if (cnt % k == 0) {
                // 待反转部分的尾结点cur在反转之后会成为局部反转链表的头结点
                // 我们需要将其反转前的next保存下来
                nextGroupHead = cur.next;
                ListNode curGroupTail = reverse(lastGroupTail.next, cur);
                lastGroupTail.next = cur; // 连接已反转部分和该反转部分
                curGroupTail.next = nextGroupHead; // 连接该反转部分和未反转部分
                lastGroupTail = curGroupTail; // Group后移，保证最终可以通过dummy.next获得目标结果
                // 保证顺序遍历
                cur = nextGroupHead;
            } else {
                cur = cur.next;
            }
        }
        return dummy.next;
    }
    
    private ListNode reverse(ListNode head, ListNode tail) {
        ListNode nextGroupHead = tail.next;
        ListNode prev = null, cur = head, next = null;
        while (cur != nextGroupHead) {
            next = cur.next;
            cur.next = prev;
            prev = cur;
            cur = next;
        }
        return head;
    }
}
```
