### 解题思路
创建了tail3 都击败了100吗。。。
这题可以直接在原链表上操作，后期优化。

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
        if(l1 == null && l2 == null)
            return null;
        if(l1 == null)
            return l2;
        if(l2 == null)
            return l1;
            
        int len1, len2;
        ListNode tail1 = l1;
        ListNode tail2 = l2;
        ListNode l3 = new ListNode(0);
        ListNode tail3 = l3;
        
        for(len1 = 0; tail1 != null; len1++, tail1 = tail1.next);
        for(len2 = 0; tail2 != null; len2++, tail2 = tail2.next);

        for(int i = 1; i < len1 + len2; i++){
            ListNode node = new ListNode(0);
            tail3.next = node;
            tail3 = tail3.next;
        }tail3.next = null;

        tail1 = l1;
        tail2 = l2;
        tail3 = l3;

        while(tail1 != null && tail2 != null){
            if(tail1.val < tail2.val){
                tail3.val = tail1.val;
                tail3 = tail3.next;
                tail1 = tail1.next;
            }
            else{
                tail3.val = tail2.val;
                tail2 = tail2.next;
                tail3 = tail3.next;
            }
        }

        if(tail1 == null && tail2 != null){
            while(tail2 != null){
                tail3.val = tail2.val;
                tail3 = tail3.next;
                tail2 = tail2.next;
            }
        }
        if(tail2 == null && tail1 != null){
            while(tail1 != null){
                tail3.val = tail1.val;
                tail1 = tail1.next;
                tail3 = tail3.next;
            }
        }
        return l3;
    }
}
```