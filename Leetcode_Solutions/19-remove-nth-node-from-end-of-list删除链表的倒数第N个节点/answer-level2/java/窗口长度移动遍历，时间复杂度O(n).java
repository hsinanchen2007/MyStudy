### 解题思路
首先确定窗口长度，start、end 分别为窗口的两边，开始需要将end到达需要的位置，start从head开始，当 end 到达时，开始start、end 同时移动，直到 end 为空
（注： 需要确定所需要窗口长度，建立head 前一个节点）
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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode init = new ListNode(0);
        init.next = head;
        ListNode start = init;
        ListNode end = init;
        int x = n+1;
        // |      0 1 2 3
        // 0 ---- 1 2 3 4
        while(end != null) {
            // x=0 时，说明前一个已到窗口边缘
            if(x == 0) {
                end = end.next;
                start = start.next;
            }else {
                // 开始一起移动
                end = end.next;
                x--;
            }
        }
        start.next = start.next.next;

        return init.next;

    }
}
```