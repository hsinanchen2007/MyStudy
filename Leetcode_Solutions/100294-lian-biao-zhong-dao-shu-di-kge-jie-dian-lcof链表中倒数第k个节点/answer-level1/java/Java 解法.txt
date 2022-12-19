### 解题思路
就是先统计长度，然后按照位置来找节点嘛

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
    public ListNode getKthFromEnd(ListNode head, int k) {
        int linkedListLength = 0;
        ListNode temp = head;
        while (temp != null) {
            temp = temp.next;
            linkedListLength  = linkedListLength + 1;
        }
        for (int i = 0; i < linkedListLength - k; i ++) {
            head = head.next;
        }
        return head;
    }
}
```