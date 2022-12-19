### 解题思路
1.每次选出l1和l2中最小的那个结点，然后将其指针指向该节点的下一个结点。2.最后一定有一个链表没有选完，因为已经有序，直接加入到l3后即可。

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
        if(l1==null)
            return l2;
        if(l2==null)
            return l1; 

        ListNode l3 = null;
        if(l1.val <= l2.val){
            l3 = l1;
            l1 = l1.next;
        }else{
            l3 = l2;
            l2 = l2.next;
        }   
        
        ListNode ans = l3;
        while(l1!=null && l2!=null){
            if(l1.val <= l2.val){
                l3.next = l1;
                l1 = l1.next;
            }else{
                l3.next = l2;
                l2 = l2.next;
            }
            l3 = l3.next;
        }

        if(l1==null)
            l3.next=l2;
        else
            l3.next=l1;
            
        return ans;
    }
}
```