### 解题思路
仍然使用快慢指针的思路，唯一需要注意的是最后元素的处理

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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null){
            if(slow.val != fast.val){
                slow.next = fast;
                slow = fast;
            }
            if (fast.next == null && slow.val == fast.val){
                slow.next = null;
            }
            fast = fast.next;
        }
        return head;
    }
}
```