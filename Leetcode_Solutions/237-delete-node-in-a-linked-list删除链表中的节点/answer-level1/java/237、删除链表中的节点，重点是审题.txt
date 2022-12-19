### 解题思路

主要是审题，传入的值就是要删除的那个值，由于我们没法知道它之前的结点，所以我们只能保留当前结点，删除它后面一个结点来实现。

也即，将当前节点的后一个结点的值复制到当前节点，然后删除后面的节点，处理好指针即可

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
        ListNode temp = node.next;
        node.val = temp.val;
        node.next = temp.next;
        
    }
}
```