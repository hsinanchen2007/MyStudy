### 解题思路
写过最短的代码哈哈哈
思路就是将链表中value值改变为下一个节点的value，因为找不到当前删除节点的前一个节点，所以这种方式是最快速的，重新赋值之后再次删除下一个节点。

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
        if(null == node && null == node.next )
        throw new IllegalArgumentException("node should can be delete");

        node.val = node.next.val;
        node.next = node.next.next;
    }
}
```