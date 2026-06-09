### 解题思路
此为Java版本的快慢指针方法。先让快指针移动k位，然后快慢指针一起移动，当快指针移动到尾部时，慢指针到达目的位置，最后返回满指针。

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
        ListNode fast=head;
        ListNode slow=head;
        while(fast!=null){
            fast=fast.next;
            if(k>0){
                k--;
            }else{
                slow=slow.next;
            }
        }
        return slow;
    }
}
```