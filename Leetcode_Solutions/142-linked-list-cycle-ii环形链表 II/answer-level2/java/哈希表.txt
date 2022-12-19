### 解题思路
遍历链表，使用Set保存遍历过节点，当遇到重复节点，则一定为环的入口节点

### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        Set<ListNode> visited = new HashSet();
        ListNode node = head;
        while(node != null){
            if(visited.contains(node)){
                return node;
            }
            visited.add(node);
            node = node.next;
        }
        return null;
    }
}
```

### 复杂度分析

时间复杂度：O(n)
空间复杂度：O(n)