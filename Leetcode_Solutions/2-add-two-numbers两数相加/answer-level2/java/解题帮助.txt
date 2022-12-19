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
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode a = l1;
        ListNode b = l2;
        //设置一个哑结点来处理会轻松很多
        ListNode headNode = new ListNode(0);
        ListNode curNode = headNode;
        int up = 0;
        do{
            //注意对null置0处理
            int sum = (a == null ? 0 : a.val) + (b == null ? 0 : b.val) + up;
            curNode.next = new ListNode(sum % 10);
            curNode = curNode.next;
            up = sum / 10;
            a = a != null ? a.next : null;
            b = b != null ? b.next : null;
        }while(!(a==null && b==null));
        if(up > 0){
            //注意最后的进位处理
            curNode.next = new ListNode(up);
        }
        return headNode.next;
    }
}
```