### 解题思路
类似合并两个有序数组一样的思路进行合并两个有序链表，唯一重点是新链表的构建，我采用构建的是存在head的链表，最后返回head.next(即第一个节点)

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
        if(l1==null){
            return l2;
        }
        if(l2==null){
            return l1;
        }
        ListNode head= new ListNode(0);
        ListNode pre=head;
        ListNode last=head;
        while(l1!=null && l2!=null){
            if(l1.val<l2.val){
                pre.next=l1;
                last=pre.next;
                pre=last;
                l1=l1.next;
            }else{
                pre.next=l2;
                last=pre.next;
                pre=last;
                l2=l2.next;
            }
        }
        if(l1!=null){
           pre.next=l1;

        }
        if(l2!=null){
            pre.next=l2;
 
        }
        
        return head.next;

    }
}
```