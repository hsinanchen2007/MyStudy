### 解题思路
使用递归方式
基本逻辑：
将当前节点和已经删除了重复节点的子链表元素进行比较；
如果当前节点和子链表中元素重复，则返回子链表；
如果当前节点和链表中元素不重复，则将子链表作为head的next节点，返回head；

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
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null){
            return null;
        }
        ListNode deletedNode = deleteDuplicates(head.next);
        ListNode copyNode = deletedNode;
        while(copyNode != null){
            if(copyNode.val == head.val){
                return deletedNode;
            }else{
                copyNode = copyNode.next;
            }
        }
        head.next = deletedNode;
        return head;
    }
}
```