### 解题思路
使用两个指针同时遍历链表，一个遍历的步长为1（慢指针，即 node= node.next），另一个遍历的步长为2（快指针,即 node = node.next.next），当快指针到达链表尾部时，根据他们的步长的差值，则此时慢指针走过的长度为快指针的一半，即慢指针刚好到达链表的中间节点。

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
    public ListNode middleNode(ListNode head) {
        ListNode fastNode = head;
        ListNode slowNode = head;
        while (fastNode!=null &&fastNode.next!=null){
            slowNode=slowNode.next;
            fastNode=fastNode.next.next;
        }
        return slowNode;
    }
}
```