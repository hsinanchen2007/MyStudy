### 解题思路
    1-2-3-4 删除3
    1-2-4-4 删除后一个4节点

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
        if(node==null){
            return;
        }
        node.val=node.next.val;
        node.next=node.next.next;
    }
}
```