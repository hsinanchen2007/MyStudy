### 解题思路
p指向需要交换的第一个结点，q指向需要交换的第二个结点，交换完之后，pre指向交换完的后一个结点，即pre = p，用以连接下一组交换。
比如第一轮，从p、q、...转变为q、p、...，此时让pre指向p，就是下一组需要交换结点的前一个结点，开始下一循环。

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
    public ListNode swapPairs(ListNode head) {
      if(head == null || head.next == null) return head;
      ListNode p = head;
      ListNode q = head;
      ListNode pre = head;
      head = head.next;
      while(p!= null){
          if(p.next != null){
            pre.next = p.next;
            q = p.next;
            p.next = p.next.next;
            q.next = p;
            pre = p;
            p = p.next;
          }
          else break;
      }  
      return head;
    }
}
```