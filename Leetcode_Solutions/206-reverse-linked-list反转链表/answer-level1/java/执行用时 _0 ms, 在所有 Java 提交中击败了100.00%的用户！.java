### 解题思路
至今未明白为何可以
“执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户”
？？？
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
    	ListNode pre = null;
    	ListNode cur = head;
        if(head == null || head.next == null){
            return head;
        }else{
            while(cur.next != null) {
                ListNode next = cur.next;
                cur.next = pre;
                pre = cur ;
                cur = next;
                next = next.next;        
            }
            cur.next = pre;
            return cur;
        }
    }
}
```