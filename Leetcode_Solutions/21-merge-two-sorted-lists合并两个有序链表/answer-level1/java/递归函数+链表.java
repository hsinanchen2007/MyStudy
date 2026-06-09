### 解题思路
递归的思想，有点懵逼

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
        //这种题第一步，都要判断特殊情况的
        if(l1==null) return l2;
        if(l2==null) return l1;
        //当第一个链表值l1小于l2时，然后判断它的下一个节点值和和l2,直到一个链表的值
        //为空时，这个递归依次返回，从最后一个一直串到前面（？还是有点蒙）
        if(l1.val<l2.val){
            l1.next=mergeTwoLists(l1.next,l2);
            return l1;
        }else{
            l2.next=mergeTwoLists(l1,l2.next);
            return l2;
        }
    }
}
```