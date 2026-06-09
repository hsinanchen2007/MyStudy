我看大家的答案都在操作指针指向，并没有创建新的对象。
如果这个函数被外部调用，我这种写法应该不会影响到原来传入的两个链表。但是不创建对象，只改变next指向会影响到原来的链表。
```Java []
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode res;
        if(l1==null || l2==null){
            return null==l1 ? l2 : l1;
        }
        
        if(l1.val<l2.val){
                res = new ListNode(l1.val);
                l1 = l1.next;
            }else{
                res=new ListNode(l2.val);
                l2 = l2.next;
            }
        ListNode p = res;
        int data ;
        while(l1!=null && l2!=null){
            if(l1.val<l2.val){
                data = l1.val;
                l1 = l1.next;
            }else{
                data=l2.val;
                l2 = l2.next;
            }
            p.next = new ListNode(data);
            p = p.next;
        }
        while(l1!=null){
            p.next = new ListNode(l1.val);
            p = p.next;
            l1 = l1.next;
        }
        while(l2!=null){
            p.next = new ListNode(l2.val);
            p = p.next;
            l2 = l2.next;
        }
        return res;
    }
}
```