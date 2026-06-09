执行结果：
通过
显示详情
执行用时 :
1 ms
, 在所有 Java 提交中击败了
93.81%
的用户
内存消耗 :
39.7 MB
, 在所有 Java 提交中击败了
46.97%
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
    public boolean hasCycle(ListNode head) {
        if(head==null||head.next==null){return false;}
        ListNode ln = head;
        ListNode stop = new ListNode(0);
        ListNode temp;
        while(ln!=null){
            if(ln==stop){
                return true;
            }
            temp=ln;
            ln=ln.next;
            temp.next=stop;
        }
        return false;
    }
}
```
