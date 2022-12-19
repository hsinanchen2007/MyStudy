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
    public ListNode removeElements(ListNode head, int val) {
        ListNode h1 = new ListNode(0);
        ListNode h2 = h1;
        while(head != null){
            if(head.val != val){
                h2.next = head;
                h2 = h2.next;
            }
            head = head.next;
        }
        h2.next = null;
        return h1.next;
    }
}
```