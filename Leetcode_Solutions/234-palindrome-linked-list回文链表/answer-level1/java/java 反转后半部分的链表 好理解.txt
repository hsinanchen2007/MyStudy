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
    public boolean isPalindrome(ListNode head) {
        if(head==null)return true;//处理输入为空的情况，返回true
        ListNode slow = findMid(head);
        if(head==slow){//处理只有一个或两个节点的情况
            if(head.next==null||head.val==head.next.val)return true;
            else return false;
        }
        reverse(slow);//反转链表的后半部分
        boolean result = compare(head,slow.next);
        reverse(slow);//恢复链表原本的结构
        return result;
    }
    public ListNode findMid(ListNode head){//快慢指针找中间节点 参考：https://blog.csdn.net/qq_21815981/article/details/79833976
        ListNode slow = head;
        ListNode fast = head;
        while(fast.next!=null&&fast.next.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        return slow;
    }
    public void reverse(ListNode slow){ //链表就地反转 参考：https://www.cnblogs.com/mwl523/p/10749144.html
        ListNode pre = slow.next;
        ListNode pCur = pre.next;
        while(pCur!=null){
            pre.next=pCur.next;
            pCur.next=slow.next;
            slow.next=pCur;
            pCur=pre.next;
        }
    }
    public boolean compare(ListNode one,ListNode two){//比较两部分链表是否相同
        while(one!=null&&two!=null){
            if(one.val!=two.val)return false;
            one=one.next;
            two=two.next;
        }
        return true;
    }
}
```
