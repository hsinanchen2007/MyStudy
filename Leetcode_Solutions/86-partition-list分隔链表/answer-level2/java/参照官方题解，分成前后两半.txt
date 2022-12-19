执行结果：
通过
显示详情
执行用时 :
2 ms
, 在所有 Java 提交中击败了
80.79%
的用户
内存消耗 :
35.7 MB
, 在所有 Java 提交中击败了
57.14%
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
    public ListNode partition(ListNode head, int x) {
        if(head==null||head.next==null)return head;
        
        ListNode pre1 = new ListNode(0);
        ListNode pre = pre1;
        ListNode aft1 = new ListNode(0);
        ListNode aft = aft1;
        ListNode t=head;
        while(t!=null){
            if(t.val<x){
                pre.next = t;
                pre = t;
            }else{
                aft.next = t;
                aft = t;
            }
            
            t = t.next;
        }
        aft.next = null;
        pre.next = aft1.next;
        
        
        return pre1.next;
    }
}
```
