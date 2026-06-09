### 解题思路

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
        //边界处理
        if(head==null){
            return head;
        }
        ListNode cur=head;
        ListNode next=cur.next;
        cur.next=null;
        while(cur!=null && next!=null){
            //临时节点，记录next的后继
            ListNode next_next=next.next;
            //后继翻转
            next.next=cur;
            //cur和next后移
            cur=next;
            next=next_next;
        }
        return cur;
    }
}
```