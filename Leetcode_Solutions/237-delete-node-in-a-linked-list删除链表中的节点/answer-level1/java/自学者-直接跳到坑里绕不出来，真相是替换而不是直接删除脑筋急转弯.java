### 解题思路
* 脑筋急转弯，正常思路是前一个节点指向下下个节点
* 没有前一个节点，就把当前节点替换为下一个节点，下一个指针指向下下个节点
* 然后删除下一个重复节点即可

### 踩坑
* 自杀，还以为出题者出错了，我滴个神
* 思维要360度大转弯才行，我滴个神
* 自己竟然在构造函数中创建了一个链表，然后进行正常删除操作，我滴个神

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
       //当前值用下一个节点的值替换
       node.val = node.next.val;
       // 被删除节点的下一个节点指向下下个节点即可
       node.next = node.next.next;
    }
}
```