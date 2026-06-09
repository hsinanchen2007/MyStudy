### 解题思路
此处撰写解题思路

### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head==null||head.next==null) return false;

        ListNode preNode = head;
        ListNode currNode = head.next;


        while (preNode != null && currNode != null&&currNode.next!=null) {
            if(preNode==currNode) return true;

            preNode = preNode.next;
            currNode = currNode.next.next;
        }
        return false;
    }
}

乌龟🐢每次走一步，兔子🐰每次走两步，如果重合了就是在转圈！没有重合兔子🐰到达终点了（==null），就是没有环！
```