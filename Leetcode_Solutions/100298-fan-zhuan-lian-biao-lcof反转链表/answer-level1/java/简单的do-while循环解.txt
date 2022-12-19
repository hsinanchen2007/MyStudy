### 解题思路
简单

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

        if(head == null){
            return null;
        }
        
        ListNode cur = head;
        ListNode res = null;
        do{

            ListNode l = new ListNode(cur.val);
            l.next = res;
            res = l;
            cur = cur.next;
        }while(cur != null);
        return res;
    }

}
```