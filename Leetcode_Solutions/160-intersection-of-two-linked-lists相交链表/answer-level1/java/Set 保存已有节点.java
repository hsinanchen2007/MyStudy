执行结果：
通过
显示详情
执行用时 :
11 ms
, 在所有 Java 提交中击败了
13.91%
的用户
内存消耗 :
39.4 MB
, 在所有 Java 提交中击败了
83.60%
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
        Set<ListNode> set = new HashSet<>();
        ListNode ln = headA;
        while(ln!=null){
            set.add(ln);
            ln=ln.next;
        }
        ListNode lnb = headB;
        while(lnb!=null){
            if(set.contains(lnb)){
                return lnb;
            }
            lnb=lnb.next;
        }
        return null;
    }
}
```
