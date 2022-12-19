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
    public static ListNode reverse(ListNode First,ListNode Last)
    {
        if(Last==null) return First;
        ListNode node=First;
        while(node.next!=Last) node=node.next;
        node.next=Last.next;
        Last.next=First;
        First=reverse(Last,node.next);
        return First;
    }
    public ListNode reverseList(ListNode head) {
            if(head==null) return head;
            head=reverse(head,head.next);
            return head;
    }
}
```