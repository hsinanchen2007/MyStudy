### 解题思路
刚开始一直报超出内存限制的错,后来发现是tm的初始的头节点head.next没有置为null,应该是打印的时候就死循环了

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
    ListNode root;

    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        } else {
            reverse(head);
            return root;
        }
    }

    public ListNode reverse(ListNode head) {
        if (head.next.next == null) {
            root = head.next;
        } else {
            reverseList(head.next);
        }
        head.next.next = head;
        head.next = null;
        return head;
    }

}
```