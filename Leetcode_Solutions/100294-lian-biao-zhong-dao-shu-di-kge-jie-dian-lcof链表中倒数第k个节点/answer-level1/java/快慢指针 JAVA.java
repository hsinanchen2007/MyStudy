### 解题思路
快慢指针

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
    public ListNode getKthFromEnd(ListNode head, int k) {
        if(head==null||k==0){
            return null;
        }
        ListNode fast=head,slow=head;
        int i=0;
        while(fast!=null){
            if(i>=k){
                slow=slow.next;
            }
            i++;
            fast=fast.next;
        }
        return i<k?null:slow;
    }
}
```