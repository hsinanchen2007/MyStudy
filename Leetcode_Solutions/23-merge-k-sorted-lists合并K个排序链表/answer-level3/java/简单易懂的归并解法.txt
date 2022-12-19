### 解题思路
此处撰写解题思路
两两比较，但是时间复杂度是（k-1）* n
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
    public ListNode mergeKLists(ListNode[] lists) {

        int len = lists.length;
        
        if(len == 0) return null;

        ListNode r = lists[0];

        if(len == 1) return r;

        for(int i =1;i < len;i++){
            r = mergeTwoLists(r,lists[i]);
        }

        return r;

    }


   public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
         ListNode curr = new ListNode(0);
         curr.next = l1;
         ListNode ls1 = l1,ls2 = l2,head = curr;
         while(l1 != null || l2 != null){
             if(l1 == null){
                 curr.next = l2;
                 l2 = l2.next;
             }else if(l2 == null){
                 curr.next = l1;
                 l1 = l1.next;
             }else if(l1.val >= l2.val){
                 curr.next = l2;
                 l2 = l2.next;
             }else{
                 curr.next = l1;
                 l1 = l1.next;
             }
             curr = curr.next;
         }

         return head.next;

    }


}
```