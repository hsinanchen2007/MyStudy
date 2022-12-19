### 解题思路
菜鸡分享

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
    int length = 0;
    public ListNode getKthFromEnd(ListNode head, int k) {
        int size = count(head);
        for (int i=0;i<size-k;i++){
            head.val=head.next.val;
            head=head.next;
        }
        return head;
 }
    public int count(ListNode head) {
        if (head == null) {
            return length;
        } else {
            length += 1;
            count(head.next);
        }
        return length;
    }
}
```