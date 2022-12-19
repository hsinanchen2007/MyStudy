### 解题思路

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
    public ListNode getKthFromEnd(ListNode head, int k) {
        ListNode one =head;
        ListNode two = head;
        while(two.next!=null&& (k!=1)){
            two=two.next;
            k--;
        }
        if(k>1){
            return null;
        }
        while(two.next!=null ){
            two=two.next;
            one = one.next;
        }
        return one;
    }
}
```