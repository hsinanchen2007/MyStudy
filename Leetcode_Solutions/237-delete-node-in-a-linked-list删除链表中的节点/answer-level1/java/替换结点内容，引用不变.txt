### 解题思路
首先，参数给出的结点为链表的一部分，该结点上一个结点的next引用为该结点，
其次，所谓的删除该结点，不过是修改该结点的值和next，修改后该结点仍然被上一个结点所引用，依然是一个完整的链表。
所以，我们只需要将后一个结点的值和next赋值给当前结点即可。

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