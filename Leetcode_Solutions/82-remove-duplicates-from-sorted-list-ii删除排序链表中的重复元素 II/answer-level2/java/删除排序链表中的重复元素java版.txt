### 解题思路
1.读清题意，是排序链表（升序），只需判断相连节点是否相等，并判断有几个连续的节点相等。
2.注意要设置一个虚拟节点作为头节点。避免极端条件。

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
        if(head==null||head.next==null)
            return head;
        ListNode vir=new ListNode(0);
        vir.next=head;
        ListNode cur=vir,n1=head,pre=head,n2=head.next;
        int a=0;
        while(n1!=null){
            a=n1.val;
            if(n1.next!=null&&n1.next.val==a){
                ListNode temp=n1;
                while(temp.next!=null&&temp.next.val==a){
                    temp=temp.next;
                }
                cur.next=temp.next;
                n1=temp.next;
            }else{
                cur=n1;
                n1=n1.next;
            }
        }
        return vir.next;
    }
}
```