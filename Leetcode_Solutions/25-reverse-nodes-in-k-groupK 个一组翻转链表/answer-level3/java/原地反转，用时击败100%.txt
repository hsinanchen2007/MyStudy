### 解题思路

![image.png](https://pic.leetcode-cn.com/e2df168561f66a1203ee12cda1ae37b60b5738b88cb2fe0c8d7475e03412a25e-image.png)

思路其实比较简单，我们首先考虑实现一个链表的反转，这个反转是的范围是`begin`和`end`之间的节点，然后把反转后的链表连接到`left`和`right`上：

`left -> begin -> ... -> end -> right`
反转成：
`left -> end -> ... -> begin -> right`

然后我们遍历原链表，用一个计数器`count`来判断是否到达`k`的倍数位置。具体实现可以看注释。

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
    public ListNode reverseKGroup(ListNode head, int k) {
        if (k < 2) {
            return head;
        }
        // 先头插法插入一个节点，主要是为了方便写代码
        ListNode left = new ListNode(0);
        left.next = head;
        ListNode cur = head;
        int count = 0;
        while (cur != null) {
            count++;
            if (count % k == 0) {
                // 此处进行反转，同时把上一轮的终点位置赋给下一轮的 left
                left = reverse(left, left.next, cur, cur.next);
                // head = left 代表此时是第一轮，第一轮反转后 head 处于终点位置
                // 需要换成 cur（原来的终点位置），才能变回新起点
                head = head == left ? cur : head;
                // cur原来是终点位置，反转后变成了起点，需更新回终点
                cur = left;
            }
            cur = cur.next;
        }
        return head;
    }

    /**
     * 反转链表
     *
     * @param left  链表前一个节点
     * @param begin 链表的起点
     * @param end   链表的终点
     * @param right 链表后一个节点
     * @return 返回链表的终点
     */
    private ListNode reverse(ListNode left, ListNode begin, ListNode end, ListNode right) {
        ListNode pre = left;
        ListNode cur = begin;
        while (pre != end) {
            ListNode temp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = temp;
        }
        // end 为头结点，begin 为尾节点
        left.next = end;
        begin.next = right;
        return begin;
    }
}
```