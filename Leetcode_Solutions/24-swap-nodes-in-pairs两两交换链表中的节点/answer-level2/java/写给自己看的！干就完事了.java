### 解题思路
用递归递归return交换的第一个数

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
        if(head==null)
            return null;
        
        ListNode second = head.next;
        if(second!=null){
            ListNode next = swapPairs(second.next);
            second.next = head;
            head.next= next;
            return second;
        }else {
            return head;
        }
            
    }
}
```