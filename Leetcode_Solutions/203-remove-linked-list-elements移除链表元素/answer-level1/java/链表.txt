### 解题思路
这题不难

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
    public ListNode removeElements(ListNode head, int val) {
        if(head == null)
            return head;
        while(head.val == val){
            head = head.next;
            if(head == null)
                return null;
        }
        //退出循环的时候是不等的时候
        ListNode fast = head.next;
        ListNode low = head;

        while(fast != null){
            if(fast.val == val){
                low.next = fast.next;
                fast = fast.next;
            }else{
                fast = fast.next;
                low = low.next;
            }
        }
        return head;
    }
}
```