### 解题思路
    将下一个节点的数值复制到要被删除的节点上，然后将下一个节点删除，史上最短的力扣代码就这样产生了，别说了，这题目考的不是编程能力，而是阅读理解，哈哈哈哈哈。

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
        node.val=node.next.val;
        node.next=node.next.next;
    }
}
```