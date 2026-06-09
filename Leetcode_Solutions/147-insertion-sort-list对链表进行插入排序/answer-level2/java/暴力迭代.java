执行结果：
通过
显示详情
执行用时 :
12 ms
, 在所有 Java 提交中击败了
81.28%
的用户
内存消耗 :
38.3 MB
, 在所有 Java 提交中击败了
56.35%
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
    public ListNode insertionSortList(ListNode head) {
        if(head==null||head.next==null)return head;
        ListNode res = new ListNode(Integer.MIN_VALUE);
        res.next = head;
        ListNode ln = head;
        while(ln!=null){
            if(ln.next==null){
                return res.next;
            }
            
            ListNode nn = ln.next;
            
            if(nn.val<ln.val){
                ln.next = nn.next;
                ListNode tt = res;
                while(tt.next!=null){
                    if(nn.val<tt.next.val){
                        nn.next = tt.next;
                        tt.next = nn;
                        break;
                    }
                    
                    tt = tt.next;
                }
            }else{
                 ln=ln.next; 
            }
           
        }
        return res.next;
    }
}
```
