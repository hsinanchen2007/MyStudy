方法一：能想到的第一个方法就是遍历一遍链表，然后记录长度，然后再遍历length/2长的链表，返回但前节点。
方法二：是一个双指针的方法，快慢指针，快指针走两步，慢指针走一步，则快指针是慢指针长度的二倍，所以快指针遍历完时，慢指针一定在链表中间。

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
    public ListNode middleNode(ListNode head) {
        ListNode f = head;
        ListNode s = head;
        while(f != null && f.next != null){
            s = s.next;
            f = f.next.next;
        }
        return s;
    }
}
```