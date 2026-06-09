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
    public void deleteNode(ListNode node) {
        node.val=node.next.val;//我们让Node有值等于他后一个节点的值
        node.next=node.next.next;//然后把我们要删除的node节点的下一个节点删除 就可以了。  
        
        
    }
}
```