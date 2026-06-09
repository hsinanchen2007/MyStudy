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
    private ListNode tou=new ListNode(0);
    public ListNode reverseList(ListNode head) {
        if (head==null)
            return null;
        ListNode pre=helper(head);
        pre.next=null;
        return tou.next;
    }
    private ListNode helper(ListNode node){
        if (node.next==null) {
            tou.next = node;
            return node;
        }
        ListNode pre=helper(node.next);
        pre.next=node;
        return node;
    }
}
```