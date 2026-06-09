### 解题思路
时刻要注意fast.next == null 的问题。

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
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null)
            return head;
        ListNode fast = head.next;
        ListNode low = head;

        while(fast != null){
            while(fast.val == low.val){
                fast = fast.next;
                if(fast == null)
                    break;
            }
            low.next = fast;
            if(fast != null){
                fast = fast.next;
                low = low.next;
            }
        }
        return head;
    }
}
```