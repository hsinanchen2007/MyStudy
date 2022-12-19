### 解题思路
此处撰写解题思路
在链表中删除某个节点，可以理解为将当前节点的下个节点的值赋值到当前节点，将当前节点的next赋值为当前节点的下个节点的下个节点。
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