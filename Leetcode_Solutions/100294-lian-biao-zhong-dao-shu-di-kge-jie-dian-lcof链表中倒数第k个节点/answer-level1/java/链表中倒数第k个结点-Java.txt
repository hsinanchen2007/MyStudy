### 解题思路
快慢指针，先让快指针走k步，然后两个指针同步走，当快指针走到头时，慢指针就是链表倒数第k个节点。
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
        ListNode slow =head;
        ListNode fast =head;
        for(int i=0;i<k;i++){
            if(fast != null)
            fast=fast.next;
        }
        while(fast != null){
            fast=fast.next;
            slow=slow.next;
        }    
        return slow;
    }
}
```