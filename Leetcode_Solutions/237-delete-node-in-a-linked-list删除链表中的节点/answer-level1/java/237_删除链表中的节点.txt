### 解题思路
讲要删除节点的下一个节点值赋予给要删除节点，即：
```java
node.val = node.next.val; 
```
要删除节点的next，设置为要删除节点的下一个next
```java
node.next = node.next.next;
```
即把要删除节点的下一个元素移动到要删除节点的位置。

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