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

//Java指针法：快慢指针，先让快指针走k步，再让慢指针与快指针同步走。快指针到头时，慢指针就是了
class Solution {
    public ListNode getKthFromEnd(ListNode head, int k) {
        ListNode p=head,q=head;
        while(p!=null&&k>0)
        {
            p=p.next;
            k--;
        }
        while(p!=null)
        {
            p=p.next;
            q=q.next;
        }
        return q;   
    }
}
```