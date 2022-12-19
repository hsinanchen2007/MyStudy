### 解题思路
方法一：快慢指针。
    一个指针一次移动一个位置，一个指针一次移动两个位置，这正好对应了中点在中间位置的性质。当快指针遍历到最后面时，为空，或者其next指向空时结束遍历，此时输出慢指针即可。

### 代码

```java

class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;

    }
}

```