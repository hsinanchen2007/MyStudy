### 解题思路
递归没有太理解，感觉使用 while 理解起来更容易一些
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
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        ListNode lnode = head;
        while(head != null && head.next != null){
           if(head.val == head.next.val){
               head.next = head.next.next;
           }else{
               head = head.next;
           }
        }
        return lnode;
    }
}
```