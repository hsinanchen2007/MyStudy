### 解题思路
 也可以在head前设置一个dummyHead

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
        ListNode p=head,q=head.next;
        if(p==null||p.next==null){
            return p;
        }
        if(head.val==val){
            head=head.next;
        }
        while(q!=null){
            if(q.val==val){
                break;
            }else{
                p=q;
                q=q.next;
            }
        }
        if(q!=null){
            p.next=q.next;
        }
        return head;
    }
}
```