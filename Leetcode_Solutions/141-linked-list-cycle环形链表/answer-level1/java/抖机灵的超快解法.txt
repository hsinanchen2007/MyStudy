### 解题思路
本题关键：解决重复访问
解决：把访问过的节点的val值设为一个不可能的数：Integer.MIN_VALUE,如果访问到的节点值等于Integer.MIN_VALUE,证明访问过了，证明有环路，返回true.
问题：失去了val的节点也就没有存在意义了，所以此题解纯粹搞笑。

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
        while(head != null){
            if(head.val == Integer.MIN_VALUE) return true;
            head.val = Integer.MIN_VALUE;
            head = head.next;
        }
        return false;
    }
}
```