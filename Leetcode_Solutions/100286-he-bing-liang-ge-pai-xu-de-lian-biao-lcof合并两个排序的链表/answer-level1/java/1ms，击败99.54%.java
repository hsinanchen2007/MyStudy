### 解题思路
此处撰写解题思路

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1==null) return l2;
        if(l2==null) return l1;
        ListNode p=l1,q=l2;
        ListNode result=new ListNode(0),res=result;
        while(p!=null&&q!=null){
            if(p.val<q.val){
                res.next=p;
                res=p;
                p=p.next;
            } else {
                res.next=q;
                res=q;
                q=q.next;
            }
        }
        if(p!=null){
            res.next=p;
        }
        if(q!=null){
            res.next=q;
        }
        return result.next;
    }
}
```