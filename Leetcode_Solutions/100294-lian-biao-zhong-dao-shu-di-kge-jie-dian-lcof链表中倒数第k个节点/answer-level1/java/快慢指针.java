### 解题思路

 双指针、快指针先走K步、然后双指针同步走、快指针到尾时慢指针所在即为所求
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
      
        ListNode fast=head,slow=head;
        if(head==null||k<0){
            return null;
        }
        while(k>0){
            fast=fast.next;
            k--;
        }
        while(fast!=null){
            slow=slow.next;
            fast=fast.next;
        }
        return slow;
    }
}
```