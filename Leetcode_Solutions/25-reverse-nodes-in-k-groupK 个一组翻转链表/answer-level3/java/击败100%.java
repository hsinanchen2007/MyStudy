### 解题思路
经典的链表反转，每次递归，对当前链表检查，对前n个进行反转，对边界进行处理好连接，第n+1递归处理。
反转思想，从头往后反转，记每段的头结点为已经反转的链表，则把链表尾部后一个插到头上，更新头节点和尾部后一个节点（尾部是不变的），相当于每次把新的查到头上

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

    private ListNode newHead;
    private ListNode preGroup;

    public ListNode reverseKGroup(ListNode head, int k) {
        int c=0;
        ListNode cur=head;
        ListNode pre=null;
        ListNode nextGroup=null;
        while(cur!=null){
            c++;
            if(c==k){
                if(preGroup!=null) preGroup.next=cur;
                nextGroup=cur.next;
                if(newHead==null) newHead=cur;
                **ListNode tail=head;**
                while(c>1){
                    **cur=tail.next;
                    tail.next=cur.next;
                    cur.next=head;
                    head=cur;**
                    c--;
                }
                // ListNode pricur=head;
                // while(pricur!=null) {
                //     System.out.println(pricur.val);
                //     pricur=pricur.next;
                // }
                tail.next=nextGroup;
                preGroup=tail;
                break;
            }else{
                pre=cur;
                cur=cur.next;
            }
        }
        if(c>1){
            if(newHead!=null) return newHead;
            else return head;
        }else{
            if(newHead==null) return head;
            if(nextGroup==null) return newHead;
            else return reverseKGroup(nextGroup,k);
        } 
    }
}
```