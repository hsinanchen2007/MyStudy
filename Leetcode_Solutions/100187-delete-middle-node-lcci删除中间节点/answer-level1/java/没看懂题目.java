### 解题思路
单链表只能删除当前指针的后续的节点，故删除本节点无法实现，曲线救国，复制下节点数据然后删除下一节点即可。

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