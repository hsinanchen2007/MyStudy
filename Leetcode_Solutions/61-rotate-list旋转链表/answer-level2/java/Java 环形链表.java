### 解题思路
链表的旋转相比于数组的旋转 更加容易，因为我们不需要移动链表中的每一个节点，只要先构造成一个环形链表， 然后在len-k%len的位置切断链表即可。


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
    public ListNode rotateRight(ListNode head, int k) {
          if (head == null || head.next == null) {
            return head;
        }
        int len = 0;
        ListNode curr = head;
        ListNode tail=null;
        while (curr!= null) {
            len++;
            tail=curr;
            curr = curr.next;
        }
        //环形链表
        tail.next=head;
        k = len-k % len;
        while (k > 0) {
            tail = tail.next;
            k--;
        }
        ListNode newHead = tail.next; //newHead 新的头节点
        tail.next = null; //切断尾节点
        return newHead;
    }
}
```