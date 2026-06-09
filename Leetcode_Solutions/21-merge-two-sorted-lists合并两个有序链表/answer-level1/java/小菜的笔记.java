### 解题思路
此处撰写解题思路
注意构造头结点和指针节点，最后返回的是头结点 。
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
        ListNode p1=l1,p2=l2;
        ListNode head=new ListNode(-1);//头结点
        ListNode p=head;//指针
    
        while(p2!=null&&p1!=null){
            if(p2.val>=p1.val){
                p.next=p1;
                p1=p1.next;
            }
            else {
                p.next=p2;
                p2=p2.next;
            }
           p=p.next;
        }
        p.next=p1==null?p2:p1;
        return head.next;

    }
}
```