### 解题思路
对链表的操作不熟悉，方法比较笨。
用栈存储ListNode，使用count计数，count值为2时，将栈内节点弹出，
完成一次交换。
节点个数为奇数时不影响。

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
        if(head == null || head.next == null) return head ;
        Stack<ListNode> stack = new Stack() ;
        int count = 0 ;
        ListNode node = new ListNode(0) ;
        node.next = null ;
        ListNode removeNode = node ;
        while(head != null){
            while(head != null && count < 2){
                stack.push(head) ;
                head = head.next ;
                count++ ;
            }
            while(!stack.isEmpty()){
                ListNode temp = stack.pop() ;
                temp.next = null ;
                removeNode.next = temp ;
                removeNode = removeNode.next ;
            }
            count = 0 ;
        }
        return node.next ;
    }
}
```