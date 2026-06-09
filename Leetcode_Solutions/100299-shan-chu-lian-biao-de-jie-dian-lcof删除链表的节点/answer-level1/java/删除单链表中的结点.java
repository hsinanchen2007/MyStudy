### 解题思路
在写链表题的时候一定要添加哨兵节点

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
    public ListNode deleteNode(ListNode head, int val) {
        ListNode node = new ListNode(0);
        ListNode curNode = node;
        curNode.next = head;
        while(curNode!=null){
            if(curNode.next.val==val){
                curNode.next = curNode.next.next;
                break;
            }
            curNode = curNode.next;
        }
        return node.next;
    }
}
```