### 解题思路
先求出链表的长度，然后计算从前数第多少个。然后返回就可以了

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
    public ListNode getKthFromEnd(ListNode head, int k) {
        if(head == null)
            return head;
        
        int len;
        ListNode tail = head;
        for(len = 0; tail != null; len++,tail=tail.next);
        
        int c = len - k;
        if(c < 0)
            return null;

        for(int i = 0; i < c; i++){
            head = head.next;
        }
        return head;
    }
}
```