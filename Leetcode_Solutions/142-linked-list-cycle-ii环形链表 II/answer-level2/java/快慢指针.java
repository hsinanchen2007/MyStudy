### 解题思路
此处撰写解题思路

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
    public ListNode detectCycle(ListNode head) {
        ListNode fast =head,slow=head;
        while(true){
            if(fast == null || fast.next == null) return null;
            fast = fast.next.next;
            slow = slow.next;
            if(fast==slow)break;
        } //定义两个指针，当两个指针相遇时在环内。此时快指针走过的路径f=2s ，且f=s+nb，所以s=nb，f=2nb，（s是满指针的路径）
        fast=head;
        while(fast!=slow){
            fast =fast.next;
            slow =slow.next;
        }//快指针回到开头与满指针一起走a步后会在入口处相遇
        return slow;
        
    }
}
```