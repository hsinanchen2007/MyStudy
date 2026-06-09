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
    public ListNode getKthFromEnd(ListNode head, int k) {
        ListNode uselessHead = new ListNode(-1);
        ListNode pre = uselessHead;
        ListNode cur = uselessHead;
        uselessHead.next = head;
        while(k>0){
            pre = pre.next;
            k--;
        }
        while(pre!=null){
            pre = pre.next;
            cur = cur.next;
        }
        return cur;
    }
}
```