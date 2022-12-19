这道题一看到时间复杂度为O(nlongn),首先想到的就是使用归并排序来完成，思路其实很简单，就是把链表分为两部分，分别对它们进行排序，然后合并这两个有序的链表就好了
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
        //题目中告诉时间复杂度O(nlongn)，所以使用归并排序或者快排
        if(head==null||head.next==null)  return head;
        //找到链表的中点
        ListNode slow=head; ListNode fast=head.next;
        //当fast指针到达结尾或者null时，此时slow到达链表中点
        while(fast!=null&&fast.next!=null){
            fast=fast.next.next;
            slow=slow.next;
        }
        //先获取链表的右半段
        ListNode right=slow.next;
        //获取链表的左半段head
        slow.next=null;
        //对链表的左半段进行排序
        ListNode left=sortList(head);
        //对链表的右半段进行排序
        ListNode next=sortList(right);
        //对左右排序好的链表进行合并
        return merge(left,next);
    }
    //实现对有序链表进行合并的操作
    private ListNode merge(ListNode left,ListNode right){
        //创建一个虚拟的头结点，完成合并的操作
        ListNode dummyHead=new ListNode(-1);
        //创建一个指针指向虚拟头结点，便于插入操作
        ListNode cur=dummyHead;
        //遍历这两个有序链表
        while(left!=null&&right!=null){
            //如果左边链表节点的值比较小，把它插入到链表中
            if(left.val<=right.val){
                cur.next=left;
                cur=cur.next;
                left=left.next;
            }else{
                cur.next=right;
                cur=cur.next;
                right=right.next;
            }
        }
        //如果左节点没有插完，把这段链表放到cur的后面就好了
        if(left!=null){
            cur.next=left;
        }
        //如果右节点没有插完，同样的操作
        if(right!=null){
            cur.next=right;
        }
        return dummyHead.next;
    }
}
```
