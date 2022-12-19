![屏幕快照 2020-01-18 下午5.55.56.png](https://pic.leetcode-cn.com/6e84744a54980f3df5301849210518b60f0b04bd77c5599de15219d231bfa17d-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-01-18%20%E4%B8%8B%E5%8D%885.55.56.png)

### 解题思路
>(1)先找到需要反转链表范围的前一个节点
>(2)反转指定范围的节点
>(3)将反转后的最后一个节点指向该范围后未反转的第一个节点
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
   public static ListNode reverseBetween(ListNode head, int m, int n) {
       // 创建一个傀儡节点，方便 m = 1 时，反转链表
        ListNode h = new ListNode(-1);
        h.next = head;
        // 求出链表长度
        int len = size(head); 
        // 排除非法情况
        if (m <= 0 || n > len) {
            return null;
        }
        // pre 记录反转范围的前一个节点
        ListNode pre = h;
        // pre 往后走，一直到反转的前一个节点
        for (int i = 1; i < m; i++) {
            pre = pre.next;
        }
        // ret 为反转的范围
        int ret = n - m;
        // 进行链表的反转
        ListNode cur = reverseList(pre.next, ret);
        // 修改反转范围链表的前一个节点的指向
        pre.next = cur;
        return h.next;
    }
    private static int size(ListNode head) {
        int count = 0;
        for (ListNode cur = head; cur != null; cur = cur.next) {
            count++;
        }
        return count;
    }
    private static ListNode reverseList(ListNode head, int ret) {
        // 
        ListNode node = head;
        // 进行反转的前一个节点
        ListNode pre = null;
        // 当前需要反转的节点
        ListNode cur = head;
        // 记录 cur 的后一个节点，方便后面修改反转范围链表的最后一个节点的指向
        ListNode next = null;
        // 进行链表的反转
        for (int i = 0; i <= ret; i++) {
            // 保存当前节点的后一个节点
            next = cur.next;
            // 修改当前节点的指向
            cur.next = pre;
            // 更新 pre 个 cur 的指向
            pre = cur;
            cur = next;
        }
        // 反转完 m - n 范围的链表后，将该范围的最后一个节点指向后面没有反转的第一个节点
        if (cur != null) {
            node.next = cur;
        }
        return pre;
    }

}
```