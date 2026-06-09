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
//删除节点一般需要该节点的前一个节点，总体思路是删除入参节点的下一个节点（用所要删除的下一个节点的值覆盖当前要删除的节点）
class Solution {
    public void deleteNode(ListNode node) {
        //node节点的下一个节点覆盖node节点，此操作导致所要删除的node节点的值不存在，此时存在两个相同的节点(入参node节点的下一个节点)
        node.val = node.next.val;
        //移动指针指向，跨越一个节点，达到删除目的
        node.next = node.next.next;
        
    }
}
```