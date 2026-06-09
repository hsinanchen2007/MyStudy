### 解题思路
遍历链表，将小于x的节点置于头部

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
    public ListNode partition(ListNode head, int x) {
        if(head==null) return head;
        ListNode p1=head.next,p2=head,temp=null;
        while(p1!=null){
            if(p1.val<x){
                temp=p1.next;
                p1.next=head;
                p2.next=temp;
                head=p1;
                p1=temp;
            }
            else{
                p1=p1.next;
                p2=p2.next;
            }
        }
        return head;
    }
}
```