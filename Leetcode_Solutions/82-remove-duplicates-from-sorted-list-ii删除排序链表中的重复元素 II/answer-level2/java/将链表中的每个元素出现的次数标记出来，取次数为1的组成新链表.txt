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
        if(head==null) return null;
        Map<Integer,Integer> map=new HashMap<>();
        ListNode p=head;
        while(p!=null){
            if(map.containsKey(p.val)){
                map.put(p.val,map.get(p.val)+1);
            }
            else
                map.put(p.val,1);
            p=p.next;
        }
        ListNode dummy=new ListNode(0);
        ListNode q=dummy;
        p=head;
        while(p!=null){
            if(map.get(p.val)==1){
                q.next=new ListNode(p.val);
                q=q.next;
            }
            p=p.next;
        }
        return dummy.next;
    }
}
```
