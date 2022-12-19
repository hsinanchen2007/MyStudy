### 解题思路
此处撰写解题思路
快慢指针这个思路很多人都想到了，我就想知道Java要怎么优化它所占用的内存呢？
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
        ListNode last = head;
        ListNode fast = head;
        // 获取链表的长度
        while (fast != null && fast.next!=null) {
            last = last.next;
            fast = fast.next.next;
        }
        return last;
    }
}
```