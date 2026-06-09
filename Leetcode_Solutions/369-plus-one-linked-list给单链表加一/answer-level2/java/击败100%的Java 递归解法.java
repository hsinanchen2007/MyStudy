### 解题思路
此处撰写解题思路

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
    public ListNode plusOne(ListNode head) {
        if (head == null) {
            return head;
        }
        ListNode head2 = returnNode(head);
        if (head2.val == 10) {
            head2.val = 0;
            ListNode first = new ListNode(1);
            first.next = head2;
            return first;
        }
        return head2;

    }

    private ListNode returnNode(ListNode node) {
        if (node.next == null) {
          node.val += 1;
          return node;
        }
        ListNode nextNode = returnNode(node.next);
        int val = nextNode.val;
        int carry = val / 10;
        nextNode.val = val % 10;
        node.val += carry;
        return node;

    }
}
```