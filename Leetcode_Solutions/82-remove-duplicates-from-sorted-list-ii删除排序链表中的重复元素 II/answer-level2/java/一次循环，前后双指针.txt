执行结果：
通过
显示详情
执行用时 :
2 ms
, 在所有 Java 提交中击败了
94.20%
的用户
内存消耗 :
36.8 MB
, 在所有 Java 提交中击败了
60.45%
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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode res = new ListNode(0);
        ListNode rr = res;
        ListNode rr2 = head;
        if(head==null)return null;
        if(head.next==null)return head;
        
       
        ListNode t = head;
        boolean same = false;
        while(t.next!=null){
            if(t.val==t.next.val){
               same = true;
            }else{
                if(!same){
                    rr.next = rr2;
                    rr2.next = t.next;
                    rr = rr2; 
                    rr2 = rr2.next;
                }else{
                    same=false;
                    rr2 = t.next;
                    rr.next = rr2;
                }
                
            }
            t = t.next;
        }
        if(same){
            rr.next = null;
        }
        return res.next;
    }
}
```
