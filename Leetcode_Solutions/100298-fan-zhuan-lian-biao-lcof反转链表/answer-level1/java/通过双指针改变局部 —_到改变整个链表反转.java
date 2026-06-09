### 解题思路
链表问题，画出来更好理解。
假设我们有一个链表：1 -> 2 -> 3 -> 4 -> 5

反转后的结果是这样：5 -> 4 -> 3 -> 2 -> 1

不难发现：其实是  ：1 <- 2 <- 3 <- 4 <- 5

我们把每个节点的指针朝向都改变了，就得到了反转后的链表。
所以我们定义两个指针 pre 和 cur。
cur 初始化即为 head。 pre 初始化时可以看作是head的前驱节点，所以初始化为null。

cur 每向后移动一次，都改变一次指针的指向，指向它的前驱节点pre，同时双指针不断向后移动（pre = cur; cur = temp;），直到cur为null 的时候结束。

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
    public ListNode reverseList(ListNode head) {
        ListNode pre = null;
        ListNode cur = head;
        while(cur != null) {
            ListNode temp = cur.next;
            cur.next = pre;
            pre = cur; // 双指针分别向后移动
            cur = temp; // 双指针分别向后移动
        }
        return pre;
    }
}
```