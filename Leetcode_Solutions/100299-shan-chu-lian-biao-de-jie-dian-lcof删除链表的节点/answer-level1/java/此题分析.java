### 解题思路
此处撰写解题思路
见代码注解
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
        if (head.val == val) {
            head = head.next;
            return head;
        }

        ListNode ret = head;
        ListNode cur = head;
        ListNode lastCur = head;

        while (cur != null){
            if (cur.val == val){
                lastCur.next = cur.next;
                break;
            }
            lastCur = cur;
            cur = cur.next;
        }
        return ret;
    }
}
```