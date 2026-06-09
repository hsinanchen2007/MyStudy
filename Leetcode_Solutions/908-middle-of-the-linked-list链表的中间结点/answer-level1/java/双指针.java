### 解题思路
典型的双指针，该题唯一需要注意的的是链表的长度是奇数还是偶数  
我的思路是奇数正常执行，将偶数当作奇数来处理（偶数+1），这样就有一致性

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
    public ListNode middleNode(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while(fast.next != null){
            slow = slow.next;
            if(fast.next.next != null){
                fast = fast.next.next;
            }else{
                fast = fast.next;
            }
        }
        return slow;
    }
    
}
```