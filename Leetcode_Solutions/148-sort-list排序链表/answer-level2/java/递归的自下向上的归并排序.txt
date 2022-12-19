思路和榜一[@jyd](/u/jyd/)的一样，只是代码更清晰。

总结： 一共用了三大知识点：
        1.遇到单链表时，记得构造他的头结点，这个头结点会非常有用，可以让咱们对第一个结点的操作更容易
        2.快慢指针找中间结点： 这个代码刚好是从这道题的上一道 将有序链表转换为二叉搜索树那里学到的（记得把标签设置为          链表），原封不动，以后想要得到链表中间结点都可以用这个代码块    
        3.就是将两个链表按顺序合并,这个也是从前面的题那里搬过来的
        

代码
```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode sortList(ListNode head) {
        ListNode prehead = new ListNode(0); //prehead 是构造的头结点，用来将两个链表合并用的
        ListNode cur = prehead;             //cur 是搭配头结点prehead使用的，用来串联起要合并的两个链表

        if(head ==null || head.next ==null) return head;    //传过来 空的或一个结点直接返回即可

        ListNode mid = this.findMidElement(head);    //findMidElement 是利用快慢指针找中间结点的        
        ListNode left = sortList(head);              //继续递归已经分离开的 left 和 right 两个链表
        ListNode right = sortList(mid);

        while(right!=null && left != null){         //从小到大合并两个链表
            if(left.val <= right.val) {
                cur.next = left;
                left = left.next;
            }else{
                cur.next = right;
                right = right.next;
            }
            cur = cur.next;
       }
       cur.next = right != null ? right : left;  //这个三目运算合并剩余链表经常用

     return prehead.next;
    }
     public ListNode findMidElement(ListNode head){ //这个就是利用快慢指针来找中间结点了
        ListNode prevPtr = null;
        ListNode fastPtr = head;
        ListNode slowPtr = head;

        while(fastPtr != null && fastPtr.next != null){
            prevPtr = slowPtr;
            slowPtr = slowPtr.next;
            fastPtr = fastPtr.next.next;
        }
        if(prevPtr != null)         //分离left和right两个链表
            prevPtr.next = null;

        return slowPtr;
     }
}```
