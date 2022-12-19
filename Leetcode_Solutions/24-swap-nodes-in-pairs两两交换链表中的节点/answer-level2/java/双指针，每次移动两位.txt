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
        if(head == null || head.next == null) return head;
        ListNode cur = head;
        ListNode curNext = cur.next;
        while(cur != null){
            int curVal = cur.val;
            if(curNext == null) break; 
            int nextVal = curNext.val;

            cur.val = nextVal;
            curNext.val = curVal;

            cur = cur.next.next;
            if(curNext.next != null){
                curNext = curNext.next.next;
            }
            
        }

        return head;
    }
}
```