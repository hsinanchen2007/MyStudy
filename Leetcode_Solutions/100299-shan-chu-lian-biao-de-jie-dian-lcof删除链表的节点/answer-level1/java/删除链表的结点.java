### 解题思路
要考虑两种特殊的情况：如果刚好删除第一个元素；如果刚好删除最后一个元素。

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
    public ListNode deleteNode(ListNode head, int val) {
        // 链表删除三部曲
        //  1. 找到p.next.val == val;  
        //  2. p.next = p.next.next;
        //  3. return head;
        if(head.next==null){
            return null;
        }
        ListNode cur = head;
        while(cur.next!=null && cur.next.next!=null){
            if(cur.val == val){
                return cur.next;
            }
            if(cur.next.val == val){
                cur.next = cur.next.next;
            }
            cur = cur.next;
        }
        if (cur.next!=null && cur.next.next==null && cur.next.val == val){
            cur.next = null;
        }
        return head;
    }
}
```