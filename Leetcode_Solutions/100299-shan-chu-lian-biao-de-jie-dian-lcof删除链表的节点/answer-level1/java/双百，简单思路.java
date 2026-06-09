### 解题思路
设置prev.next = head，并令curr=prev，一次性遍历

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
    public ListNode deleteNode(ListNode head, int val) {
        ListNode prev = new ListNode(0);
        prev.next = head;
        ListNode curr = prev;
        while(curr.next != null){
            if(curr.next.val == val){
                curr.next = curr.next.next;
                return prev.next;
            }
            else{
                curr = curr.next;
            }
        }
        return prev.next;
    }
}
```