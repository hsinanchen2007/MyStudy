### 解题思路
此处撰写解题思路
删除一个节点，就是把之前的节点的next变为要删除节点的next。但题目无法得出之前节点，只能用要删除的节点的next覆盖掉的要删除的节点.
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
            //change node to nextnode
            node.val = node.next.val;
            node.next = node.next.next;
    }
}
```