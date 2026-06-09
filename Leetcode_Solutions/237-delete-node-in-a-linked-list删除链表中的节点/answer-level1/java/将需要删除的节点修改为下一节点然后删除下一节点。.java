### 解题思路
这个题目的问题就在于，并不是普通的删除，接口参数并未提供需要删除的节点的前一个节点。
如LinkNode =[0,1,2,3]，这个时候只是传入了2这个节点，需要进行删除。
那么就只能复制下一节点的值到当前节点，并删除当前节点的下一节点。
也就是要删除链表中的一个node 可以考虑把需要删除的节点修改为下一节点，然后删除下一个节点。

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