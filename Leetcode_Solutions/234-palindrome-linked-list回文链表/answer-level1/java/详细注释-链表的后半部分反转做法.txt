### 解题思路
见注释

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
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null){
            return true;
        }

        ListNode slow = head;
        ListNode fast = head;
        // 若链表长度为奇数，此时慢指针移动到链表中间位置(n/2+1)，快指针在最后一个节点
        // 若链表长度为偶数，此时慢指针移动到链表(n/2)的位置，快指针在最后一个节点的下一个位置，即 null
        while (fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }

        // 标记准备反转的起点，待反转完成，该节点就是反转链表的尾节点
        ListNode reverseHead = slow.next;
        // 若不在进行反转前将 slow 的 next 引用其置为 null，则会在反转后导致正向链表的尾节点（slow）和反转链表的尾节点（slow.next） 相互引用造成死循环，最终超时
        slow.next = null;
        // 将慢指针之后的节点进行反转，得到反转链表的头节点
        ListNode reverseHalfEnd = reverseList(reverseHead, slow);
        
        // 将链表的正向头节点和反向头节点的值进行遍历对比，若有不同则不是回文链表
        while (head != null){
            if (head.val != reverseHalfEnd.val){
                return false;
            }
            head = head.next;
            reverseHalfEnd = reverseHalfEnd.next;
        }
        return true;
    }

    public ListNode reverseList(ListNode cur, ListNode slow){
        ListNode pre = slow;
        ListNode next = cur;
        while (next != null){
            next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
     }
}
```