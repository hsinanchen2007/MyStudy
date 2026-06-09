### 解题思路
时间复杂度为O(N), N 为链表长度；空间复杂度为O(1)

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
    public int getDecimalValue(ListNode head) {
        int x = 0;
        while(head != null){
            x = x * 2 + head.val;
            head = head.next;
        }
        return x;
    }
}
```