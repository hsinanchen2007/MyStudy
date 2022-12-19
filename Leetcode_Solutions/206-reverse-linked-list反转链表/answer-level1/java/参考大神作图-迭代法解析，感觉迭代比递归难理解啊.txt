### 解题思路
此处撰写解题思路

### 代码
![反转列表-迭代法.mp4](9ea56e53-ce73-4f6e-9bb7-803847286986)

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
    //迭代法解决
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        ListNode pre = null;
        ListNode current = head.next;
        head.next = pre;
        while(current != null){
            pre = head;
            head = current;
            current = current.next;
            head.next = pre;
        }
        return head;
    }
}
```