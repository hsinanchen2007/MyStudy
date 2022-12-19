###解题思路
一次遍历即可完成
new一个新的节点newHead为null
将原链表的值按次序插到新链表的头部即可完成


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
        
        
        ListNode newHead = null;
        ListNode next = null;

        while(head!=null)
        {
            next=head.next;
            head.next=newHead;
            newHead=head;
            head=next;
        }

        return newHead;

    }
}
```