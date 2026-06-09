### 解题思路
先判断该链表是否为空，为空则需抛出异常
再想删掉一个节点后，该节点的前一个节点需指向该节点的后一个节点

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
        if(node==null||node.next==null){
            throw new IllegalArgumentException("node should be avild");
        }
        node.val=node.next.val;
        node.next=node.next.next;
    }
}
```