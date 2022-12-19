### 解法一：哈希表
判断一个链表是否有环，可以遍历该链表每个结点，若有环，则一定会有结点被重复访问。
因此使用哈希表记录下每个遍历到的结点，如果当前结点已存在于哈希表中，则有环；如果访问到空结点，则无环。

时间复杂度：O(n)。
空间复杂度：O(n)。

代码：

```java
public class Solution {
    public boolean hasCycle(ListNode head) {
        Set<ListNode> set = new HashSet<ListNode>();
        while(head != null)
        {
            if(set.contains(head))  return true;
            else                    set.add(head);
            head = head.next;
        }
        return false;
    }
}
```

### 解法二：双指针（快慢指针）
之前的题解里曾提到过快慢指针这种双指针解法，一般用于判断环形序列、循环序列。
本题的判断环形链表也一样，通过设置一快一慢双指针，快指针一次走两步，慢指针一次走一步，若存在环形序列（环形链表），则快慢指针将会在某个时刻重合；若不存在环形序列（环形链表），则快慢指针不会重合且快指针会先到达链表的终点（即访问到空结点）。

时间复杂度：O(n)。
空间复杂度：O(1)。

代码：

```java
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head == null || head.next == null)
            return false;
        ListNode fast = head.next, slow = head;
        while(fast != slow)
        {
            if(fast == null || fast.next == null)
                return false;
            fast = fast.next.next;
            slow = slow.next;
        }
        return true;
    }
}
```