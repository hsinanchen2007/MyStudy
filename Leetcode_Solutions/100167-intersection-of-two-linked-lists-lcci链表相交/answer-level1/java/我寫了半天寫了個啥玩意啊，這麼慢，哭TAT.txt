### 解题思路
搞不懂傳入的headA和headB指的是第一個元素 直接報錯兩次 爆哭TAT

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(headA == null || headB == null){
            return null;
        }
        ListNode temp1 = headA;//原來=headA.next
        while(temp1!=null){
            ListNode temp2 = headB;//原來是headB.next
            while(temp2!=null){
                if(temp1==temp2){
                    return temp2;
                }
                temp2=temp2.next;
            }
            temp1=temp1.next;
        
        }
        return null;
    }
}
```