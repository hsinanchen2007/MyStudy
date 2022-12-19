### 解题思路
先计算链表长度，然后直接返回最中间的那个节点即可。

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
        if (head == null){
            return null;
        }

        int len = 0;
        ListNode dummy = head;
        while (dummy != null){
            dummy = dummy.next;
            len++;
        }

        int midLen = len / 2;
        while (midLen > 0){
            head = head.next;
            midLen--;
        }
        return head;
    }
}
```