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
    public ListNode swapPairs(ListNode head) {
        
        int count =0;

        ListNode falNode = new ListNode(-1);
        falNode.next = head;

        ListNode prev = falNode; 

        while( head != null && head.next != null ){
            ListNode firstNode = head;
            ListNode secondNode = head.next;
            
            prev.next = secondNode;
            firstNode.next = secondNode.next;
            secondNode.next = firstNode;


            prev = firstNode;
            head = firstNode.next;
        }
        return falNode.next;
        
    }
}
```