### 解题思路
注意几点：
1.设一个头节点，指向合并之后的链表头
2.设一个合并指针，用于指向最新合并如注释here处

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
        if(l1==null)return l2==null?null:l2;
        if(l2==null)return l1==null?null:l1;
        ListNode res=new ListNode(-2);
        ListNode cur=res;
        while(l1!=null&&l2!=null){
            if(l1.val<l2.val){
                res.next=l1;
                l1=l1.next;
            } else{
                res.next=l2;
                l2=l2.next;
            }
            res=res.next;//here，这里需要让合并指针指向等待增加合并节点的位置。
        }
        res.next=(l1==null)?l2:l1;
        return cur.next;
    }
}
```