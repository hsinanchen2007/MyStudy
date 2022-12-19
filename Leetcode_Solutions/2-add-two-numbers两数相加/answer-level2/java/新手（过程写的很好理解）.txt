### 解题思路
此处撰写解题思路

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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int num = 0;
        ListNode head = new ListNode(0);
        ListNode node = head;
        int sum = 0;
        while(l1 != null || l2 != null || num != 0) {
            if(l1 == null && l2 != null){
                sum = l2.val + num;
                l2 = l2.next;
            }else if(l2 == null && l1 != null) {
                sum = l1.val + num; 
                l1 = l1.next;
            }else if(l1 == null && l2 == null) {
                sum = num;
            }else {
                sum = l1.val + l2.val + num;
                l1 = l1.next;
                l2 = l2.next;
            }
            if(sum >= 10) {
                num = 1;
                node.next = new ListNode(sum - 10);
            }else {
                num = 0;
                node.next = new ListNode(sum);
            } 
            node = node.next;    
            
        } 
        return head.next;
    }
}
```