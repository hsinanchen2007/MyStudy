### 解题思路
1.创建一个头结点用来连排序后的链表
2.比较两链表当前值，小的就放入新链表，更新next值
3.最后把非空链表剩余部分挂上新链表

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
        ListNode res=new ListNode(0),next=res;

        while (l1!=null && l2!=null){
            if (l1.val>=l2.val){
                next.next=l2;
                next=next.next;
                l2=l2.next;
            }
            else{
                next.next=l1;
                next=next.next;
                l1=l1.next;
            }
        }
        if (l1!=null)
            next.next=l1;
        if (l2!=null)
            next.next=l2;
        return res.next;
    }
}
```