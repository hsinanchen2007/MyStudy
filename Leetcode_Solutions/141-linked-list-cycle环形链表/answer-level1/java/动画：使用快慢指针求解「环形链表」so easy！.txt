
### 题目解析

这道题是快慢指针的**经典应用**。

设置两个指针，一个每次走一步的**慢指针**和一个每次走两步的**快指针**。

- 如果不含有环，跑得快的那个指针最终会遇到 null，说明链表不含环。
- 如果含有环，快指针会超慢指针一圈，和慢指针相遇，说明链表含有环。

### 动画描述

![](https://pic.leetcode-cn.com/56cc96bd74192a8b4affb2b9bc5358ce0d9adba77cab2cfb2b00ff89a941f122-file_1561712279013)

### 代码实现

```java [-java]
//author:程序员小吴
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) return true;
        }
        return false;
    }
}
```

