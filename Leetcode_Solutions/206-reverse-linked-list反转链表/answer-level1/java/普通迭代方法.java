### 解题思路
迭代过程中，新建一个next节点，防止逆转节点时断链。
迭代{
    next = head.next;//存放下一个节点
    head.next = pre; //节点逆置
    pre = head;
    head = next;//往后移动head节点
}
迭代条件是head != null，最后后移head节点为null结束迭代。

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
    public ListNode reverseList(ListNode head) {
        if(head==null||head.next==null){
            return head;
        }

        ListNode pre = null;
        ListNode next = null;

        while(head!=null){
            next = head.next;
            head.next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
}
```