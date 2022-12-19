### 解题思路
绕啊绕，，，
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
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;
        while(curr != null){
            ListNode temp = curr.next;
            // 交换指针
            curr.next = prev;
            prev  = curr;
            curr = temp;
        }
        return prev;
    }
}
```