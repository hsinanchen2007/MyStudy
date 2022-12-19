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
    public ListNode removeElements(ListNode head, int val) {
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;
        ListNode cur = dummyHead;
        while( null != cur.next){
            if(cur.next.val == val){
                ListNode delNode = cur.next;
                cur.next = delNode.next;  
                delNode.next = null;
            }else{
                cur = cur.next;
            }
        }

        return dummyHead.next;
    }
}
```