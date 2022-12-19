执行结果：
通过
显示详情
执行用时 :
641 ms
, 在所有 Java 提交中击败了
7.93%
的用户
内存消耗 :
45.3 MB
, 在所有 Java 提交中击败了
39.58%
的用户
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
        if(head==null||head.next==null)return head;
        return sort(head);
    }
    private ListNode sort(ListNode ln){
        if(ln.next==null)return ln;
        ListNode lns = new ListNode(0);
        ListNode tlns = lns;
        ListNode tln = ln;
        ListNode temp = ln.next;
        while(temp!=null){
            if(temp.val<ln.val){
                tlns.next = temp;
                tlns = tlns.next;
                temp = temp.next;
                tlns.next = null;
                tln.next = temp;
            }else{
                temp = temp.next;
                tln = tln.next;
            }
        }
       
        if(lns.next!=null){
            ListNode prehalf = sort(lns.next);
            lns.next = prehalf;
        }
        temp = lns;
        while(temp.next!=null){
            temp = temp.next;
        }
        if(ln.next!=null)ln.next = sort(ln.next);
        temp.next = ln;
         
        return lns.next;
    }
}
```
