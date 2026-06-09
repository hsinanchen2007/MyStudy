### 解题思路
双指针法

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
    public int kthToLast(ListNode head, int k) {
        ListNode first = head;
        ListNode second = head;
        while(k > 0){
            first = first.next;
            k--;
        }
        while(first != null){
            first = first.next;
            second = second.next;
        }
        return second.val;
    }
}
```