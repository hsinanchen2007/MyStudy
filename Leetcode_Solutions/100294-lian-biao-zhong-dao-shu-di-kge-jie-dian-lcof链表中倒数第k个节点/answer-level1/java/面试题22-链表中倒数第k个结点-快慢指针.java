### 解题思路

快慢指针 fast 和 slow 

fast 先走 k步，如果k步没走完就到尾部了，抛出异常

fast 走完k步后，fast 与 slow 再同时开始走

当fast 到达尾部之后，slow 指向的刚好是是 倒数第 k 个数

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

        if(head == null || k < 1){
            return null;
        }

        int preStep = k;
        ListNode fast = head;
        ListNode slow = head;
        while(preStep > 0){
            if(fast != null){
                fast = fast.next;
                preStep --;
            }else {
                throw new IllegalArgumentException();
            }
        }

        while(fast != null){
            fast = fast.next;
            slow = slow.next;
        }

        return slow;

    }
}
```