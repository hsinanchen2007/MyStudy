### 解题思路
本题思路比较清晰，想要删除一个节点，我们可以把该节点的下一个节点值赋予该节点，此时该节点充当下一个节点，再把该节点指向下下个节点，由此相当于把该节点的原来下一个节点抛弃掉，本题切忌使用哨兵节点充当待删除节点的前置节点，因为即使使用该哨兵节点指向重复节点的下一个节点，本身原链表根本没有变化，变化的只是哨兵节点的那条“线”，除非你可以通过遍历找到该重复节点的前置节点，否则该方法是不合适的。

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
        ListNode prev = new ListNode(0);
        prev.next = node;
        node.val  = node.next.val;
        node.next = node.next.next;
    }
}
```