### 解题思路
    采用虚拟头结点方法删除链表中的节点。

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
        ListNode p=new ListNode(0); 
        p.next=head;
        ListNode pre=p;
        ListNode cur=head;
        while(cur!=null)
        {
            if(cur.val==val)
            {
                pre.next=cur.next;
                cur.next=null;
                break;
            }
            
            else
            {
                pre=cur;
                cur=cur.next;
            }
        }
        return p.next;
    }
}
```