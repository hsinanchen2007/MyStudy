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
       ListNode tmp = head;
        while (head != null){
            tmp = tmp.next;
            head = head.next;
            if (head!=null){
                head = head.next;
                if (head == tmp)
                    return true;
            }
            else 
                return false;
        }
        return false; 
    }
}
```