### 解题思路
这一题开始不知道怎么做，以为差一个参数。看了答案才意识到这道题的巧妙。
说白了用后一个节点替换当前节点。
把后一个节点的值赋给当前节点，然后让后一个节点的nextnext等于后一个节点就可以了。

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