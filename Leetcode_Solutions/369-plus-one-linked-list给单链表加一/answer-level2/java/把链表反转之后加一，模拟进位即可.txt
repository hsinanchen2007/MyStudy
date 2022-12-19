首先把链表反转。

然后把反转后的链表进行加一操作，利用除法获得进位，利用取余获得当前位置值。

java 代码：

```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode plusOne(ListNode head) {
        head = reverse(head);
        ListNode p = head;
        int add = 1;
        while(p != null)
        {
            int sum = p.val + add;
            add = sum/10;
            p.val = sum%10;
            p = p.next;
        }
        head = reverse(head);
        if(add != 0)
        {
            ListNode node = new ListNode(add);
            node.next = head;
            head = node;
        }
        return head;
    }
    
    
    ListNode reverse(ListNode head)
    {
        if(head == null || head.next == null)
            return head;
        ListNode newhead = reverse(head.next);
        head.next.next = head;
        head.next = null;
        return newhead;
    }
        
}
```
