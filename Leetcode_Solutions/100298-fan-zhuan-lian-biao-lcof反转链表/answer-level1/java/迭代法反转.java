### 解题思路
迭代法反转

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
        if(head == null) return null;
        ListNode cur = head;
        while (cur.next != null) {
            ListNode nextNode = cur.next;
            cur.next = nextNode.next;
            nextNode.next = head;
            head = nextNode;
        }
        return head;
    }
}
```