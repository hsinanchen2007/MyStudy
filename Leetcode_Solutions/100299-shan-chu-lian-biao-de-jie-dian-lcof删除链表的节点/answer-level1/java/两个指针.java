### 复杂度分析
时间复杂度：O(n)
空间复杂度：O(1)

### 解题思路
使用 pre 指针记录当前结点 node 的前一个结点
当遇到需要删除的结点时，pre.next = node.next 即可
用虚头结点方便处理边界

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
    public ListNode deleteNode(ListNode head, int val) {

        // 虚头结点
        ListNode voidHead = new ListNode(0);
        voidHead.next = head;

        // 当前结点
        ListNode node = head;
        
        // 前一个结点
        ListNode pre = voidHead;

        while (node != null && node.val != val) {
            pre = node;
            node = node.next;
        }
        if (node != null && node.val == val) {
            pre.next = node.next;
        }
        return voidHead.next;
    }
}
```