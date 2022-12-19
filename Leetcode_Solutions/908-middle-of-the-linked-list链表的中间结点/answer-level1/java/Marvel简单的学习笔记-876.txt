### 快慢指针
本题与题目234回文链表一样都使用了快慢指针。
设置一快一慢的双指针，快指针一次走两步，慢指针一次走一步，快指针走完两圈，慢指针走完一圈，快指针走完一圈，慢指针走到一半，这样就找到了中点。
不难发现，快慢指针不仅适合用于判断环形序列循环序列，还可以用于寻找中点的场景。

### 代码

```java
class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode fast = head, slow = head;
        while(fast != null && fast.next != null)
        {
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }
}
```