### 解题思路
由于不知道上一个节点，所以不能把当前节点直接去掉，只能改值。
1.改值，与下一个节点一样，
2.记录下一个节点的下一个节点，
3.把下一个节点架空，便于回收，
4.当前节点与2记录的节点相连
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
        ListNode node1=node.next.next;
        node.next.next=null;
        node.next=node1;
    }
}
```