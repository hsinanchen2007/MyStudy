### 解题思路
1.先计算连表长度
2.计算中间元素下标
3.从前向后找到中间元素，返回后续链表

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
    public ListNode middleNode(ListNode head) {
        int len = 0;
        ListNode cur = head;
        //计算链表长度
        while (cur != null) {
            len++;
            cur = cur.next;
        }
        if (len == 1) return head;
        if (len == 2) return head.next;
        //寻找中间结点
        int middle = len / 2;
        cur = head;
        int idx = 0;
        while (cur.next != null) {
            idx++;
            cur = cur.next;
            if (idx == middle) {
                return cur;
            }
        }
        return null;
    }
}
```