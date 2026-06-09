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
    public ListNode middleNode(ListNode head) {
        if(head == null || head.next == null) {
            return head;
        }
        int len = getListLen(head);
        ListNode fastNode = head;
        ListNode slowNode = head;
        while (fastNode != null && fastNode.next!= null && fastNode.next.next != null) {
            fastNode = fastNode.next.next;
            slowNode = slowNode.next;
        }
        if ((len & 1) == 1) {
            return slowNode;
        } else {
            return slowNode.next;
        }
    }

    private int getListLen(ListNode node) {
        int res = 0;
        while (node != null) {
            node = node.next;
            res++;
        }
        return res;
    }
}
```