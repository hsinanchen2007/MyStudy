### 解题思路


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
    public static ListNode insertionSortList(ListNode head) {
    	if(head==null)
    		return null;
        ListNode res = head;
        head=head.next;
        res.next=null;
        ListNode p = res;
        while(head!=null)
        {
            ListNode next = head.next;
            if(res.val>=head.val)//比新链表的第一个小，放在开头
             {
             head.next=res;
             res=head;
             }
            else{
            while(p.next!=null&&p.next.val<=head.val)//找插入位置插入
            {
                p=p.next;
            }
            head.next=p.next;
            p.next=head;   
            }
            head=next;
            p=res;
        }
        return res;
    }
}
```