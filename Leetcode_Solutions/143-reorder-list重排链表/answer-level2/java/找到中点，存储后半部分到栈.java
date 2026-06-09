执行结果：
通过
显示详情
执行用时 :
11 ms
, 在所有 Java 提交中击败了
17.98%
的用户
内存消耗 :
46.2 MB
, 在所有 Java 提交中击败了
43.45%
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
    public void reorderList(ListNode head) {
        if(head==null||head.next==null||head.next.next==null)return;
        ListNode fast=head.next;
        ListNode slow=head;
        while(fast!=null&&fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        Stack<ListNode> st = new Stack<>();
        while(slow.next!=null){
            st.push(slow.next);
            slow = slow.next;
        }
        ListNode start = head;
        while(!st.isEmpty()){
            ListNode ln= st.pop();
            ln.next = start.next;
            start.next = ln;
            start = ln.next;
        }
        start.next = null;
        
        
    }
}
```
