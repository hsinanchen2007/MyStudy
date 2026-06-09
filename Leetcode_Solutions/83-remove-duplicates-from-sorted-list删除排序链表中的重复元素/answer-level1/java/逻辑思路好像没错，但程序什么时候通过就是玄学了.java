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
    public ListNode deleteDuplicates(ListNode head) {
        if(head==null||head.next==null){
            return head;
        }
        ListNode p=head,q=head.next;
        while(q!=null){
            if(q!=null&&q.val==p.val){
                ListNode tmp=q.next;
                p.next=tmp;
                q=q.next;
            }else{
                p=q;
                q=q.next;
            } 
        }
        return head;
    }
}
```