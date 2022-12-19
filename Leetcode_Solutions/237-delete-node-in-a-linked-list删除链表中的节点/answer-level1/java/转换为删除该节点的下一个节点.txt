## 思路分析

因为给参数只有一个，即是链表的节点，所以需要在此节点上做文章。由于给的是节点，故相当于了给了该链表从此节点开始的所有节点，所以直接转换为删除该节点的下一个节点：
1. 先把下一个节点的值赋予该节点；
2. 删除下一个节点；

## 代码实现

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
        node.next=node.next.next;
    }
}
```