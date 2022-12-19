### 解题思路
嵌套了一个循环，将下一个不重复的节点赋给fast，但是这样复杂度o有点高。。

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
    public ListNode deleteDuplicates(ListNode head) {
        if(head==null||head.next==null)return head;
        ListNode slow=head;
        ListNode fast=head.next;
        while(fast!=null){
            while(fast!=null&&fast.val==slow.val){fast=fast.next;}  
            slow.next=fast;
            slow=slow.next;
            fast=fast==null?fast:fast.next;                     
        }
        return head;
    }
}
```