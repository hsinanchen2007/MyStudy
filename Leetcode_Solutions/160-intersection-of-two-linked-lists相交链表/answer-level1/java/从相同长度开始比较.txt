执行结果：
通过
显示详情
执行用时 :
2 ms
, 在所有 Java 提交中击败了
96.25%
的用户
内存消耗 :
48.3 MB
, 在所有 Java 提交中击败了
5.61%
的用户
```
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
        if(headA==null)return null;
        if(headB==null)return null;
        
        ListNode ln = headA;
        int la=0;
        while(ln!=null){
            la++;
            ln=ln.next;
        }
        ListNode lnb = headB;
        int lb=0;
        while(lnb!=null){
            lb++;
            lnb=lnb.next;
        }
         ln = headA;
         lnb = headB;
        if(la>=lb){
            int m = la-lb;
            while(m>0){
              ln=ln.next;  
              m--;
            }
            while(lb>0){
                if(ln==lnb)return ln;
                ln = ln.next;
                lnb=lnb.next;
                lb--;
            }
        }else{
            int m = lb-la;
            while(m>0){
              lnb=lnb.next;  
              m--;
            }
            while(la>0){
                if(ln==lnb)return ln;
                ln = ln.next;
                lnb=lnb.next;
                lb--;
            } 
        }
        return null;
    }
}
```
