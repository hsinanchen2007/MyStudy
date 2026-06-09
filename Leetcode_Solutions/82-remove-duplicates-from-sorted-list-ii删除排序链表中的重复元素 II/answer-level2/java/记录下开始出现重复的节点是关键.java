1. 首先加个头结点方便操作。
2. p1指向某数字开始的结点，p2指向重复结束的结点，pp1和pp2是他们的父结点

```java
/*
 * @lc app=leetcode.cn id=82 lang=java
 *
 * [82] 删除排序链表中的重复元素 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if(head==null){
            return null;
        }
        ListNode p1=head,p2=head;
        ListNode hhead=new ListNode(Integer.MIN_VALUE);
        hhead.next=head;
        ListNode pp1=hhead,pp2=hhead;
        while (p2!=null) {
            if(p2.val==p1.val){
                p2=p2.next;
                pp2=pp2.next;
            }else{
                if(p1.next==p2){
                    p1=p1.next;
                    pp1=pp1.next;
                }else{
                    p1=p2;
                    pp1.next=p2;
                }
            }
        }
        if(p1.next==p2){
            p1=p1.next;
            pp1=pp1.next;
        }else{
            p1=p2;
            pp1.next=p2;
        }
        return hhead.next;
    }
}
// @lc code=end


```