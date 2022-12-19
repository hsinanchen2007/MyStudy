### 解题思路
此处撰写解题思路

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
    // 基本思路是找到m节点和它的前驱，n节点和它的后驱，把m到n这段反转，再连接
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (head == null || head.next == null) {
            return head;
        }
        int i = 1;
        ListNode nodeM = head;
        ListNode preM = null;
        while (i < m) {
            preM = nodeM;
            nodeM = nodeM.next;
            i++;
        }
        // 没有前驱则不断开
        if (preM != null) {
            preM.next = null;
        }
        ListNode nodeN = nodeM;
        while (i < n) {
            nodeN = nodeN.next;
            i++;
        }
        // n节点后驱
        ListNode nextN = nodeN.next;
        // 记得断开
        nodeN.next = null;
        ListNode temp = reverse(nodeM);
        // 没有前驱则不连接
        if (preM != null) {
            preM.next = temp;
        }
        // 连接
        nodeM.next = nextN;
        // 返回答案也要注意
        return preM == null ? temp : head;
    }
    public ListNode reverse(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode prev = head;
        ListNode cur = head.next;
        while (cur != null) {
            ListNode temp = cur.next;
            cur.next = prev;
            prev = cur;
            cur = temp;
        }
        head.next = null;
        return prev;
    }
}
```