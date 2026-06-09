### 解题思路
主要是要考虑一下如果head就是要删除的元素的情况
之后的思路就是找到要删除结点的前一个结点，将被删除元素的前一个结点指向被删除元素的后一个节点
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
        ListNode cur = head;
        ListNode p = null;
        while(head!=null) {
            if (head.val!=val) 
            {
                break;
            }
            head = head.next;
        }
        while (cur!=null&&cur.next!=null) {
            if (cur.next.val == val) {
                p = cur.next;
                cur.next = p.next;
            }
            cur = cur.next;
        }
        return head;
    }
}

