### 解题思路
先删除开头所有val节点
第一个不等于val的节点固定为头结点
双指针法删除后续值为val的点

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
   public  ListNode deleteNode(ListNode head, int val) {

            if(head == null){
                return head;
            }

            ListNode pre = new ListNode(0);
            pre.next = head;

            ListNode check = new ListNode(0);
            check.next = head;

            ListNode needed = new ListNode(0);
            //删除链表开头连续的值为val的节点
            while (check.next.val == val && check.next != null){
                check.next = check.next.next;
            }
            //当扫描到部位val的节点时，上述循环终止，
            //第一个不为val的节点为返回链表的头结点，用needed指向它
            if (check.next != null){
                needed.next = check.next;
                pre.next = check.next;
                check.next = check.next.next;
            }
            //双指针法删除val节点
            while (check.next != null){
                if (check.next.val == val){
                    pre.next.next = check.next.next;
                }
                pre.next = check.next;
                check.next = check.next.next;
            }
        return needed.next;
    }

}
```