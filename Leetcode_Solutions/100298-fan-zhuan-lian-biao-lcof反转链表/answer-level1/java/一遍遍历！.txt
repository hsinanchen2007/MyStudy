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
    public ListNode reverseList(ListNode head) {

        if(head == null)
            return null;
        ListNode tmphead = head,prev = head,cur = prev.next;
        if(cur == null)
            return head;
        
        while(cur != null){
            prev.next = cur.next;
            cur.next = tmphead;
            tmphead = cur;
            cur = prev.next;
        }
        return tmphead;
    }
}
```