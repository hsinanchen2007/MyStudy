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
      public int getDecimalValue(ListNode head) {

        if (head == null) {
            return 0;
        }
        int ans = 0;
        ListNode ptr = head;
        while(ptr != null) {
            ans <<=1;
            ans += ptr.val;
            ptr = ptr.next;
        }
        
        
        return ans;
    }
}
```