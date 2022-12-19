### 解题思路
解决难点1：因为方法只能传递一个参数的限制，所以传递给下一层递归栈的参数必定是当前操作结点的next结点。
2：当传入下一层的结点为next结点时，便可以知道，next结点是无法拿到它的前结点的。所以反转指向要做的事情不能是此层结点指向此层结点的前结点，再重申一次这是因为没法传入两个参数（如果传入两个参数，可以将head和head.next传入，按传统方式反转指向）
所以必须在当前结点就反转下一个结点的指向。也就是这个递归方法的精髓所在 head.next.next = head 。完成了移花接木，用当前结点操作了下一个结点的指向。这样就可以每次传入next结点做递归了
实际的过程要比思路更简单一点。直接递归到最后一个结点，再由倒数第二结点进行指向反转，依此往上递归。
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
   public ListNode reverseList(ListNode head){
            /*head==null用来判别是否一开始就传入了空指针，head.next==null判别是否递归到最底层*/
            if (head == null || head.next == null) return head;
            ListNode p = reverseList(head.next);
            /*这是最重要的步骤，意义是在此结点改变了下一个结点的前结点指向。*/
            head.next.next = head;
            /*将此结点的next指针置空*/
            head.next = null;
            /*返回新的头结点*/
            return p;
        }
}
```