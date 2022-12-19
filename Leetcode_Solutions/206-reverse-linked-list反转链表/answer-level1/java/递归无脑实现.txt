递归无脑实现。递归无非分三个步骤，
1、先弄清楚递归什么时候终止，  当链表中没有元素，或者只有一个元素时，递归终止。
2、将大问题转换为小问题，    例如1->2->3->4->5-null 
题目中给了头节点， 即此时头节点为1， 此时函数的输出结果应该是 5->4->3->2->1-null
若此时输入头节点为2， 此时函数的输出结果应该为5->4->3->2-null
接下来应该显而易见了，我们只用传入 head.next 此时理解为传入2节点，返回的应该是  5->4->3->2 然后让此时的这个节点的下一个节点指向头节点，即完成了该递归过程
3、第三个步骤无非是返回值类型， 由上述2的分析，该递归过程的返回值就是一个经过反转后的链表。






class Solution {
    public ListNode reverseList(ListNode head) {
      

   if(head==null || head.next==null) 
   return head;
        ListNode newNode = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return newNode;
    }
}