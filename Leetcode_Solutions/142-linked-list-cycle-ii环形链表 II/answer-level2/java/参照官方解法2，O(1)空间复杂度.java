执行结果：
通过
显示详情
执行用时 :
1 ms
, 在所有 Java 提交中击败了
99.62%
的用户
内存消耗 :
34.6 MB
, 在所有 Java 提交中击败了
47.06%
的用户
```
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head==null||head.next==null)return null;
        ListNode same = getSame(head);
        if(same==null)return null;
        ListNode f = head;
        while(true){
            if(f==same){
                return f;
            }
            f=f.next;
            same=same.next;
        }
      //  return null;
         
    }
    private ListNode getSame(ListNode head){
        ListNode fast = head;
        ListNode slow = head;
        while(fast!=null&&fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
            if(slow==fast){
                return slow;
            }
        }
        return null;
    }
}
```
