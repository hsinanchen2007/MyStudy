处理下头节点是删的点 或者整个为空， 判断node下一个节点是否等于target，如果等于 就把当前节点的指针指向 target的下一个节点。

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
        if(head == null) return null;
        if(head.val == val) return head.next;
  
       ListNode node = head;
       while( node.next != null){
           if(node.next.val == val){
             
               node.next = node.next.next;
               return head;
           }
           
           node =node.next;
     
       }
       
       return null;
    }
}
```