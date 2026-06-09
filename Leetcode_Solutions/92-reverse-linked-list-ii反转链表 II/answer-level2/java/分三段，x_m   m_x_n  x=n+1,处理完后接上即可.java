执行结果：
通过
显示详情
执行用时 :
0 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
34.5 MB
, 在所有 Java 提交中击败了
79.78%
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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if(head==null||head.next==null)return head;
        
        int i=1;
        
        ListNode x = new ListNode(0);
        ListNode h = new ListNode(0);
        ListNode mm = null;
        h.next = head;
        ListNode temp = head;
        ListNode last = h;
        while(temp!=null){
            if(i==m){
                last.next=null;
                x.next = temp;
                mm = temp;
            }else if(i>m&&i<=n){
                if(i==m+1){
                    mm.next = null;
                }
                ListNode v = temp.next;
                temp.next = x.next;
                x.next = temp;
                temp = v;
            }else if(i==n+1){
                mm.next = temp;
                break;
            }else if(i<m){
                last = last.next;
            }
            if(i<=m||i>n){
                temp= temp.next;
            }
            i++;
        }
        last.next = x.next;
        return h.next;
    }
}
```
