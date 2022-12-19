### 解题思路
使用2个指针，first 和 second 第一个指针每次走一步，第二个指针每次走2步；

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
    public ListNode middleNode(ListNode head) {
        ListNode pre = head;
        ListNode curr = head;
        if (head == null){
            return null;
        }
        while (curr != null){

            curr = curr.next;

            if (curr != null){
                pre = pre.next;
                curr = curr.next;
            }else {
                break;
            }

        }
        return pre;
    }
}
```