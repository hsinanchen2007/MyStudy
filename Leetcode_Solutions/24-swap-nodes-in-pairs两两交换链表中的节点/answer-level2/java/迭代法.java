### 解题思路

这里用到了一个头部哨兵节点，很巧妙。
详细的图解步骤可以参考大神的解法 https://leetcode.windliang.cc/leetCode-24-Swap-Nodes-in-Pairs.html
这题的变量命名很重要，否则会绕晕的

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
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode point = dummy;
        while(point.next != null && point.next.next != null){
            ListNode swap1 = point.next;
            ListNode swap2 = point.next.next;
            point.next = swap2;
            swap1.next = swap2.next;
            swap2.next = swap1;
            point = swap1;
        }
        return dummy.next;
    }
}
```