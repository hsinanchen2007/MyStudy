**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {

        //找到需要逆置的第一个节点以及该节点的前驱节点,并设置一个新节点保存原来的head节点,用作逆直过后返回该新链表
        ListNode pre_head=null;
        ListNode result=head;
        ListNode new_head=null;
        
        int len = n-m+1;
        while(head!=null&&m>1)
        {
            pre_head=head;
            head=head.next;
            m--;
        }
        
        ListNode modify_node=head;
        //从找到的需要逆直的节点head开始,逆置(n-m+1)个单位
        while(len!=0)
        {
            ListNode l_next = head.next;
            head.next=new_head;
            new_head=head;
            head=l_next;
            len--;
        }
        //逆置过后,head节点会跑到逆置后逆置段尾节点的后面一个节点,所以需要将逆置段的尾节点与该head节点相连,如果引用不改变,该引用跟着节点后面跑,始终指向该节点,如果引用改变,则引用指向的节点也会不同.
        modify_node.next=head;
        //循环结束后,需要将逆置前需要逆置的头节点的前驱节点指向逆置后的头节点,但也要判断是否从第一个节点开始,如果从第一个节点开始的话pre_head指向的就是空节点.
        if(pre_head!=null){
             pre_head.next=new_head;
        }
       else{
           result=new_head;
       }
        return result;
    }
}