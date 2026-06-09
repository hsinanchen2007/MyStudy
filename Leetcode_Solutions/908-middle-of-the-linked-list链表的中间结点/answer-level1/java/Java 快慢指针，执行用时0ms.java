### 解题思路


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
        if (head == null) {
            return null;
        }
        ListNode mid = head;
        while (head.next != null) {
            head = head.next;
            mid = mid.next;
            if (head.next != null) {
                head = head.next;
            }else {
                break;
            }
        }
        return mid;

    }
}
```