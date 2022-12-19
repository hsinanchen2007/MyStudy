### 解题思路
题目是求中间结点，很自然的想到一种解法：先计算出链表的长度，然后再遍历链表，遍历到一半时返回。

对于这类题目，还有比较经典的做法就是双指针了：一慢一快，利用两个指针遍历的步长差来达到预期目的。这道题是核心是遍历到一半就停止，那么我们可以联想到，跑步时如果一个人比另外一个人速度快一倍，那么相同时间下，快的人跑到**终点**时，慢的人恰好在**中点**。

### 代码

#### 单指针

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
        int length = 0;
        ListNode temp = head;
        while (temp != null) {
            length++;
            temp = temp.next;
        }
        int i = 0;
        while (head != null && i < length / 2) {
            head = head.next;
            i++;
        }
        return head;
    }
    
    public ListNode middleNode(ListNode head) {
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
}
```

#### 双指针

```java
class Solution {
    
    public ListNode middleNode(ListNode head) {
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
}
```
