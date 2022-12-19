### 解题思路
  通常我们删除链表中的元素的时候，都是将要删除元素的上一个元素的next指向要删除的元素的next，就直接可以删除了，
但是在这个题里面，我们无法拿到要删除的链表前面的值，仅仅可以拿到，要删除节点以及后面的节点，所以我们用后面节点的值覆盖该节点的val，然后把后面节点断了，也就是该节点的next指向next的next～～～～

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
            ListNode last= node.next;
            node.val=last.val;
            node.next=node.next.next;
    }
}
```