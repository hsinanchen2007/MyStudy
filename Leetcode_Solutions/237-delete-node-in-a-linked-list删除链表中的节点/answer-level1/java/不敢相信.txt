### 解题思路
这题目。。。

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
    public void deleteNode(ListNode node) {
        //删除链表节点   5 <=> 1 值交换
        node.val = node.next.val;
        node.next = node.next.next;
    }
}
```