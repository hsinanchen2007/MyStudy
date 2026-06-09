欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
几乎所有题目都会提供多种解法，真诚求star！

# 解法一：三指针

以题给示例1->2->3->4为例，三指针遍历过程如下图。

![question0024-1.png](https://pic.leetcode-cn.com/6072c90f462fd9c88f7849665d60ab278557e6ece6821121fabb2d0e807b1c74-question0024-1.png)

时间复杂度是O(n)，其中n为链表的长度。
空间复杂度是O(1)。

执行用时：0ms，击败100.00%。消耗内存：35.1MB，击败63.60%。

```java
public class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;
        ListNode cur1 = dummyHead;
        //如果链表中只有0个或者1个节点，无需进行任何交换操作
        if (cur1.next == null || cur1.next.next == null) {
            return dummyHead.next;
        }
        ListNode cur2 = cur1.next, cur3 = cur2.next;
        while (true) {
            cur2.next = cur3.next;
            cur1.next = cur3;
            cur3.next = cur2;
            cur1 = cur2;
            if (cur1.next == null || cur1.next.next == null) {
                return dummyHead.next;
            }
            cur2 = cur1.next;
            cur3 = cur2.next;
        }
    }
}
```

# 解法二：递归

递归的终止条件：链表中只有0个或1个节点。

时间复杂度和空间复杂度均是O(n)，其中n为链表的长度。

执行用时：1ms，击败100.00%。消耗内存：35.1MB，击败63.14%。

```java
public class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;
        //如果链表中只有0个或者1个节点，无需进行任何交换操作
        if (dummyHead.next == null || dummyHead.next.next == null) {
            return dummyHead.next;
        }
        ListNode cur1 = dummyHead.next, cur2 = cur1.next;
        cur1.next = swapPairs(cur2.next);
        dummyHead.next = cur2;
        cur2.next = cur1;
        return dummyHead.next;
    }
}
```
