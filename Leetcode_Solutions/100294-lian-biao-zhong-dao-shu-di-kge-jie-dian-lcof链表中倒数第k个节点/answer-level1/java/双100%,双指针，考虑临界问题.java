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
    public ListNode getKthFromEnd(ListNode head, int k) {
    if (head==null||k<=0){
            return null;
        }
        ListNode slow=head,fast=head;
        while (k-->0){
            if (fast.next!=null){
                fast=fast.next;
            }else if (k==0){
              return slow;

            }else {
                return null;
            }
        }

        while (fast.next!=null){
            slow=slow.next;
            fast=fast.next;
        }
        return slow.next;
    }
}
```