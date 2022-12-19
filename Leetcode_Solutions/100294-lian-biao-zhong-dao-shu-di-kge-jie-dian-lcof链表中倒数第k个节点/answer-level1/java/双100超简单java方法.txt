### 解题思路
思路过于简单一看就懂不多解释了

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
        int cnt = 0;
        ListNode cur = head;
        ListNode pre =head;
        while(cnt<k)
        {
            cur = cur.next;
            cnt++;
        }       
        if(cur==null)
            return head;
        while(cur.next!=null)
        {
            pre = pre.next;
            cur = cur.next;
        } 
        return pre.next;
    }
}
```