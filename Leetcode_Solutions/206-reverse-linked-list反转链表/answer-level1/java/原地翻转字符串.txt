### 解题思路

(1)链表为空，或者只有一个节点，直接返回head
(1)pre表示前一个节点，cur表示当前节点，每次将当前节点指向前一个节点，即可
(3)temp临时存储当前节点的下一个节点；
(4)当处理完之后，把头结点的next置为null

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
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode pre = head;
        ListNode cur = head.next;
        ListNode temp;
        while(cur != null){
            temp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = temp;
        }
        head.next = null;
        return pre;
    }
}
```