### 解题思路

递归:
- 当剩余节点数 <= 1 时, 直接返回当前节点
- node1标记为当前节点, node2标记为当前节点的后驱, 再交换
- node1的后驱应该指向node2的后驱(应该是node2之后变过的节点), node2的后驱变为node1
- 返回node2节点

### 代码

```java
class Solution {
    public ListNode swapPairs(ListNode head) {
        // 当前节点数为0或者1时, 不足以交换
        if(head == null || head.next == null) return head;
        // 节点数大于1, 交换node1和node2
        ListNode node1 = head;
        ListNode node2 = head.next;
        // node1的后驱指向node2之后的节点
        node1.next = swapPairs(node2.next);
        // node2的后驱指向node1
        node2.next = node1;
        // 返回node2节点
        return node2;
    }
}
```