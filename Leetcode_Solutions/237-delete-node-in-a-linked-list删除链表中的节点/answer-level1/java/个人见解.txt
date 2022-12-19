### 解题思路
  通常，删除链表节点是修改前节点的next指针，在获取不到前节点的情况下，使用后一节点替换当前节点的值，再将next.next的节点替换next节点。
  简单来说：用后面的节点替换前面的节点，完成删除节点操作

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
       node.next  = node.next.next;
    }
}
```