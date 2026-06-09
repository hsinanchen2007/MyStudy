### 解题思路
快慢指针相遇

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
        ListNode n1,n2;
        n1 = n2 = head;
        while(n1!=null && n2!=null){
            n1 = n1.next;
            n2 = n2.next;
            if(n2 == null){
                return false;
            }
            else{
                n2 = n2.next;
            }
            if(n1 == null){
                return false;
            }
            else if(n1 == n2){
                return true;
            }
        }
        return false;
    }
}
```