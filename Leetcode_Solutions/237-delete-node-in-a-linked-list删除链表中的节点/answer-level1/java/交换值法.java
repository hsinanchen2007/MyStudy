### 解题思路
1.删除当前结点，但没传入head，不知道当前结点的prev是啥；
2.没法在链表中删除当前结点，怎么办呢？
那就把下一个结点的值放到当前结点，删除下一个结点好了。

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
          // 如果为 null 则抛出异常, 确保了 node 不是尾节点
        if (node == null || node.next == null) {
            throw new IllegalArgumentException("node should be valid and can not be the tail node");    
        }   
        //即本来是1、2、3、4、5
        // 将 node 后面结点的值覆盖掉 node 的值，即3变为4，变为1、2、4、4、5
        node.val = node.next.val;
        //断链，删除原来是4节点的值
        node.next = node.next.next;

        
    }
}
```