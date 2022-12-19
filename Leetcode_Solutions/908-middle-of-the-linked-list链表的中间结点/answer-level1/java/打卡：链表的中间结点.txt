

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
        int n=0;
        ListNode cur = head;
        while(cur != null){
            n++;
            cur=cur.next;
        }
        int l=0;
        cur = head;
        while(l<n/2){
            l++;
            cur = cur.next;
        }
        return cur;
    }
}
```