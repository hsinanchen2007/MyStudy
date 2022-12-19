执行结果：
通过
显示详情
执行用时 :
2 ms
, 在所有 Java 提交中击败了
91.75%
的用户
内存消耗 :
38 MB
, 在所有 Java 提交中击败了
38.83%
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
        if(head==null||head.next==null){
            return head;
        }
        ListNode i=head, j=head.next;
        while(j!=null){
            if(j.val==i.val){
                i.next = j.next;
                j = j.next;
            }else{
                i = i.next;
                j = j.next;
            }
        }
        return head;
    }
}
```
