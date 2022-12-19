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
        
        StringBuffer sb = new StringBuffer();
        
        while (head != null) {
            sb.append(head.val+"");
            head = head.next;
        }
        
        return Integer.parseInt(sb.toString(), 2);
        
    }
}
```