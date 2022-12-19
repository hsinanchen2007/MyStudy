### 解题思路
利用一个假的头指针， 这是比较通用的一个技巧， 感觉这题目最重要的就是这点

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
        if(head == null) return null;
        if(head.val == val) return head.next;

        ListNode dummy = new ListNode(0);
        dummy.next = head;

        while(head != null && head.next != null) {
            if(head.next.val == val) {
                head.next = head.next.next;
                break;
            }
            head = head.next;
        }
        return dummy.next;
    }
}
```