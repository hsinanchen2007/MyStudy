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
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null)
        {
            return head;
        }

        //新建一个newhead
        ListNode newhead = null;
        while(head != null)
        {
            ListNode temp = head.next;//建一个temp放丢失head那条链表
            head.next = newhead;
            newhead = head;
            head = temp;
        }
        return newhead;
    }
}
```