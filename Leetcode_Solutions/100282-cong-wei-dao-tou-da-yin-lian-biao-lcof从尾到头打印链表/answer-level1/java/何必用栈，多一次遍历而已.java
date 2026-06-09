### 解题思路
此处撰写解题思路

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
    
    public int[] reversePrint(ListNode head) {
        
        int len = length(head);
        
        int[] nodes = new int[len];
        reversePrint(head, nodes, len-1);
        
        return nodes;
    }
    
    
    private void reversePrint(ListNode node, int[] nodes, int i) {
        
        if (node == null) {
            return;
        }
        
        reversePrint(node.next, nodes, i-1);
        nodes[i] = node.val;
    }
    
    
    private int length(ListNode node) {
        
        int len = 0;
        while (node != null) {
            len++;
            node = node.next;
        }
        
        return len;
    }
}
```