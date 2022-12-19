### 解题思路
对于链表类问题常用的解决方式有设置临时节点，遍历链表等，此处用删除节点的后续节点去覆盖需要删除掉的节点即可达到目标。

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