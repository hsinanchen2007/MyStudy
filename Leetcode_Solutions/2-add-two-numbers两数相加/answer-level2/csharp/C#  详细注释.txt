````
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        //新建链表
        ListNode head=new ListNode(0);
        //指向新建链表头，p可以理解为C里面的指针
        ListNode p=head;
        //存储进位数
        int carryNum=0;
        while(l1!=null||l2!=null){
            int num1=l1!=null?l1.val:0;
            int num2=l2!=null?l2.val:0;
            int sum=num1+num2+carryNum;
            carryNum=sum/10;
            //每遍历一个新建一个节点
            ListNode newNode=new ListNode(sum%10);
            //指向新节点
            p.next=newNode;
            p=newNode;
            l1=l1!=null?l1.next:null;
            l2=l2!=null?l2.next:null;
        }
        //针对两个链表最后一位相加，如果进位，新链表需要新建一个节点
        if(carryNum>0){
            p.next=new ListNode(carryNum);
        }
        //head指向第一个节点0
        return head.next;
    }       
}




````