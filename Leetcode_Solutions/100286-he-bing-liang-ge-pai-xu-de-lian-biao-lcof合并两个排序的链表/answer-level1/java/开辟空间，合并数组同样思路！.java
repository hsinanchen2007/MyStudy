### 解题思路
我觉得应该有更好的办法，不需要另外开辟空间，直接在当前链表上操作，但我不会啊！

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
    //和合并两个有序数组的思路差不多
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode i = l1;
        ListNode j = l2;
        ListNode head = new ListNode(0);
        ListNode temp = head;
        while(i!=null&&j!=null){
            if(i.val <= j.val){
                temp.next = new ListNode(i.val);
                i = i.next;
            }else{
                temp.next = new ListNode(j.val);
                j = j.next;
            }
            temp = temp.next;
        }
        if(i==null&&j!=null){
            while(j!=null){
                temp.next = new ListNode(j.val);
                temp = temp.next;
                j = j.next;
            }
        }
        if(i!=null&&j==null){
            while(i!=null){
                temp.next = new ListNode(i.val);
                temp = temp.next;
                i = i.next;
            }
        }
        return head.next;
    }
}
```