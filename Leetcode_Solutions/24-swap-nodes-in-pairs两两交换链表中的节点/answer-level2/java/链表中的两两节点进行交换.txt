### 解题思路
偶数则两两交换，奇数则最后一个元素不动即可。
重点：头节点的处理，后续节点其实就是交换
可以思考下每k个连续节点进行逆序如何处理？（借助于栈）

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
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        // 确认头节点！！！
        ListNode result = head.next;
        head.next = head.next.next;
        result.next = head;

        ListNode pre = head; // 前面一对已经交换完成的尾节点
        ListNode p = pre.next;
        while (p != null && p.next != null) {
            ListNode tmp = p.next;
            p.next = p.next.next;

            pre.next = tmp;
            tmp.next = p;
            pre = p;
            p = p.next;
        }
        return result;
    }
}
```