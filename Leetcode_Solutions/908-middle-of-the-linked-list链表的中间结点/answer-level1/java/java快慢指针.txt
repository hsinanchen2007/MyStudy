### 解题思路
java快慢指针

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
        
        if(head==null){
            return null;
        }

        ListNode p = head;
        ListNode q = head;

        while(q!=null && q.next!=null){
            p = p.next;
            q = q.next.next;
            
        }

        return p;
    }
}
```