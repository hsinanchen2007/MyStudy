### 解题思路
- 1.循环先找最大值。
- 2.循环找到最大值递减至k的位置。返回

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
    public int kthToLast(ListNode head, int k) {
        int max = 0;
        int r = 0;
        ListNode new_head = head;
        ListNode cur_node = head;
        while (cur_node != null) {
            max++;
            cur_node = cur_node.next;
        }

        cur_node = head;
        while (cur_node != null && max >= k) {
            if (max == k)
                r = cur_node.val;
            max--;
            cur_node = cur_node.next;
        }
        return r;
    }
}
```