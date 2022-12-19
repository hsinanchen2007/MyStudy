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
       ListNode dummyHead = new  ListNode(-1);

       dummyHead.next = head;

       ListNode prev = dummyHead;

       while(prev.next != null){
          if(prev.next.val == val){
              prev.next = prev.next.next;
          } else{
              prev = prev.next;
          } 
       }

        return dummyHead.next;
    }
}
```