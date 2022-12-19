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
    public boolean hasCycle(ListNode head) {
        if(head == null || head.next == null) return false;
        ListNode head1 = head.next;       
        while(head != null && head1 != null){
            if(head1 == head){
                return true;
            }
            head = head.next;
            head1 = head1.next;
            if(head1!= null)
            head1 = head1.next;
        }
        return false;
    }
}
```