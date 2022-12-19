### 解题思路
    小伙伴们，你们有没有遇到，一次翻转后，head指向的节点输出的链表不再是原来链表的所有值，会漏到某些值。针对这种情况，我们需要一个节点固定指向每次翻转后新链表的头结点，这样就不会遗漏掉某些值。
    链表翻转问题一般都要引进一个头结点dummy，dummy.next=head,这样可以保证链表翻转时dummy.next一直指向翻转之后的链表头结点。
    说明：reverse函数返回的是下一次翻转的前一个节点。
    具体思路看代码注解。

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
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode pre = dummy;
        while(pre!=null){
            pre = reverse(pre,k);
        }
        return dummy.next;
    }

    public ListNode reverse(ListNode dummy,int k){
        ListNode curt = dummy;
        ListNode n1 = dummy.next;
        //判断能否走k步不越界
        for(int i=1;i<=k;i++){
            curt = curt.next;
            if(curt==null){
                return null;
            }
        }
        ListNode nk=curt;
        ListNode nk1=curt.next;
        // dummy->n1->...->nk->nk1->...
        // 已知 dummy n1 ...nk nk1...
        // 翻转 n1到nk
        ListNode cur=n1, pre =dummy,tmp=null;
        while(cur!=nk1){
            tmp=cur.next;
            cur.next=pre;
            pre=cur;
            cur=tmp;
        }
        //得到三段 ：dummy->n1 , dummy<-n1<-n2...<-nk, nk1->...
        dummy.next=nk;//or pre 
        n1.next = nk1 ;// nk.next
        return n1;//下一次 翻转从nk1开始，返回其前一个节点，即n1
    }
}
```