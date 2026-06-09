### 解题思路
1.如果head为空，直接返回head
2.如果head的val刚好是目标值，则直接返回head.next（此处不需管head.next是否空）
3.循环找到节点，如果找到next节点的值为目标val，则将当前节点的next指向next的next即可，同时break退出循环（因为链表数值不重复）
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
        if(head == null){
            return head;
        }
        if(head.val == val){
            return head.next;
        }
        ListNode tmp=head;
        while(tmp!=null){
            if(tmp.next!=null &&  tmp.next.val==val){
                tmp.next=tmp.next.next;
                break;
            }
            tmp=tmp.next;
        }
        return head;
    }
}
```