### 解题思路


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
    public ListNode swapPairs(ListNode head) {

        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode Pre = dummy;
        ListNode first = Pre.next;
        ListNode second = null;
        if (first!=null){
            second = first.next;
        }
        while (second!=null){
            Pre.next = second;
            ListNode secondNext = second.next;
            second.next = first;
            first.next = secondNext;
            Pre = first;
            first = secondNext;
            if (first != null){
                second = first.next;
            }else {
                second = null;
            }
        }
        return dummy.next;
    }
}
```