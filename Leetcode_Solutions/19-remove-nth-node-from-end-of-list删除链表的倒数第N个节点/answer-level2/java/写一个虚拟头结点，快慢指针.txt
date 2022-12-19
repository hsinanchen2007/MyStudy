### 解题思路
写一个虚拟头结点，快慢指针

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0);//虚拟头结点
        dummy.next = head;
        ListNode slow = dummy, fast = dummy;
        int times = 0;
        while (fast != null) {
            if(times > n) {
                slow = slow.next;
            }
            times++;
            fast = fast.next;
        }
        slow.next = slow.next.next;
        return dummy.next;
    }
}
```