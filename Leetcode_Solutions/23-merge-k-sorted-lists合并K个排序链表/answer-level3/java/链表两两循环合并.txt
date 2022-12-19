### 解题思路
合并k个链表可以看成将k个链表依次合并，所以划分为k-1次合并，
新建一个返回链表，初值设置为第一个链表，再设置一个指针指向头结点，一个指针指向首结点，然后进行k-1次两个链表的合并，最后返回返回链表的首节点即可。因为是升序排列，所以将小的合并链表节点插入返回链表当前节点的前面，设置两个指针的目的是方便将要合并的链表节点插入返回链表中。


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
    public ListNode mergeKLists(ListNode[] lists) {
        int length=lists.length;
        if(length==0)return null;
        ListNode retrurnListhead=new ListNode(0);
        retrurnListhead.next=lists[0];
        ListNode returnpoint=retrurnListhead.next;
        ListNode returnpointpre=retrurnListhead;
        for(int i=1;i<length;i++){
            returnpoint=retrurnListhead.next;
            returnpointpre=retrurnListhead;
            while(returnpoint!=null&&lists[i]!=null){
                if(returnpoint.val>=lists[i].val){
                    returnpointpre.next=lists[i];
                    lists[i]=lists[i].next;
                    returnpointpre.next.next=returnpoint;
                    returnpointpre=returnpointpre.next;
                }else{
                    returnpointpre=returnpoint;
                    returnpoint=returnpoint.next;
                }
            }
            if(lists[i]!=null)returnpointpre.next=lists[i];
        }
        return retrurnListhead.next;
    }
}
```