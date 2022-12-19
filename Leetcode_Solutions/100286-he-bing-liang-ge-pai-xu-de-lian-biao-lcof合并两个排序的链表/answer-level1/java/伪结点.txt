### 解题思路
此处撰写解题思路
主要思路就是要用到伪结点，和谁小谁做下一个节点。
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
        //整体思路就是谁小谁拿下来，放到链表里。
        ListNode p = new ListNode(1);
        ListNode q = p;//把p看成伪头结点，一会输出p.next作为头结点，但是因为p会改变，所以重新弄个q。
        while(l1!=null&&l2!=null){
            if(l1.val<l2.val){
                p.next = l1;
                l1 = l1.next;
            }
            else{
                p.next = l2;
                l2 = l2.next;
            }
            p = p.next;
        }
        p.next=(l1==null)?l2:l1;
        return q.next;
    }
}
```