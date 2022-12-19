### 解题思路
方案一：创建一个虚拟头节点，只需讨中间节点值是否为要删除节点；
方案二：分类讨论当删除节点为头节点时，和删除节点为中间节点时；

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
    public ListNode removeElements(ListNode head, int val) {
        while(head != null && head.val == val) {
            ListNode delNode = head;
            head = head.next;
            delNode.next = null;
        }
        if(head == null) {
            return null;
        }
        ListNode pre = head;
        while(pre.next != null) {
            if(pre.next.val == val){
                ListNode delNode = pre.next;
                pre.next = delNode.next;
                delNode.next = null;
            } else {
                pre = pre.next;
            }
        }
        return head;
    }
}
```