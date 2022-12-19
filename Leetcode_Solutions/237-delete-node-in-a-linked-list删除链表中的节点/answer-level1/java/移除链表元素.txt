### 解题思路
此处撰写解题思路

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
        //让要删除的该node节点的后面的值（node.next.val）覆盖该node节点
        node.val = node.next.val;
        //将该node节点的指向下一节点（“已死亡”）的节点
        node.next = node.next.next;
    }
}
```