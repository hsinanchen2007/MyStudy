### 解题思路
因为可以找到当前节点，不能找到当前节点的前一节点，所以将当前节点的下一节点的值赋知道当前节点，然后直接删除当前节点的下一节点就可以

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
        node.val = node.next.val;
        node.next = node.next.next;
    }
}
```