![image.png](https://pic.leetcode-cn.com/7ed5b71d1ec58130f5b97ed89891dc49985b35cbaba0f60f86317e4d37e3276f-image.png)

### 这道题用双指针，一个走得快，一个走得慢，直到两个指针碰到（如果碰不到说明没有环）；碰到之后将slow指针设置为head，fast为当前节点，接着两个指针分别每次只走一个单位，直到自此碰头，就是头结点了，下面说下为什么再次碰头就是头结点：
![image.png](https://pic.leetcode-cn.com/f9f4fb7fedd361bda8867378b2a3f2d3c3dc438e3d444b4b7510fcedafa5c449-image.png)

### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;
        while (fast!=null&&fast.next!=null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow==fast) {
                slow = head;
                while (slow!=fast) {
                    slow = slow.next;
                    fast = fast.next;
                }
                return slow;
            }
        }
        return null;
    }
}
```