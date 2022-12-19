/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        //分别算出两个链表的长度
        int len_a=0;
        int len_b=0;
        //保存当前节点的位置
        ListNode head_a=headA;
        ListNode head_b=headB;
        while(headA!=null)
        {
            len_a++;
            headA=headA.next;
        }
         while(headB!=null)
        {
            len_b++;
            headB=headB.next;
        }
        //将两个链表归到同一长度,既较长的链表头节点向前移动两个链表长度的差值
        
        //如果链表A比链表B长的话,则移动链表A的头节点，否则移动链表B的头节点
        if(len_a>len_b){
            int number1=len_a-len_b;
            while(number1!=0){
                head_a=head_a.next;
                number1--;
            }
        }
        else{
            int num2=len_b-len_a;
            while(num2!=0){
                head_b=head_b.next;
                num2--;
            }
        }
        
      

        //将链表A和链表B从较短的链表开始同时向前遍历,遇到相等的节点既是重合节点.

        while(head_a!=null&&head_b!=null){
            if(head_a==head_b){
                return head_a;
            }
           head_a=head_a.next;
           head_b=head_b.next;
        }
        return null;
    }
}