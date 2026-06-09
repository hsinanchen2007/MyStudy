### 解题思路

判断链表是否有环，经典题目了，惯用套路就是快慢指针了，慢指针走一步，快指针走两步 ，
如果链表有环，在某一时刻，两个指针肯定能够相遇。

### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        //定义快慢指针
        ListNode slow = head;
        ListNode fast = head;
        while (slow !=null && fast !=null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast)
                return true;
        }
        return false;
    }
}
```