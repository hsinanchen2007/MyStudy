### 解题思路
设置一个头结点，指向head；
先设置三个移动的点：
1. pre：从头结点开始移动；
2. cur：从head开始移动；
3. pos：从head开始移动。
先让pos移动N步，然后pre和cur同时和pos一起向前移动。
当pos到达链表的结尾并且为null时，cur正好在要删除的节点上，pre在前一个节点；
此时只要将pre指向cur的下一个节点，这样便删除了cur节点

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head == null){
            return null;
        }
        ListNode pre = new ListNode(0);
        pre.next = head;
        ListNode res = pre;
        ListNode cur = head;
        ListNode pos = head;
        for(int i = 0; i < n; i++){
            pos = pos.next;
        }
        while(pos != null){
            pre = pre.next;
            cur = cur.next;
            pos = pos.next;
        }
        pre.next = cur.next;
        return res.next;
    }   
}
```