### 解题思路
都在注释里

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
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null)
            return null;
        //这是一个小技巧，弄一个假节点，下一个指向head，返回时返回假节点的下一个，可以处理头结点（类似dp数组长度加1）
        ListNode ans = new ListNode(0);
        ans.next = head;
        //pre前置节点，当cur和next不等时，pre指向next
        ListNode pre = ans;
        //cur当前节点
        ListNode cur = head;
        //next下一个节点
        ListNode next = head.next;
        //当前cur是否等于next节点，当不等时判断isEqual的值，false时pre指向cur，cur指向next，next指向next的下一个
        //true时，pre的下一个指向next，cur指向next，next指向next的下一个，并把isEqual置成false
        boolean isEqual = false;
        while (next != null) {
            if (cur.val == next.val) {
                next = next.next;
                isEqual = true;
            } else {
                if (isEqual) {
                    pre.next = next;
                    cur = next;
                    next = next.next;
                    isEqual = false;
                } else {
                    pre = cur;
                    cur = next;
                    next = next.next;
                }
            }
        }
        //针对特殊情况，1-2-3-4-4，跳出循环时判断一下isEqual的值
        if (isEqual) {
            pre.next = next;
        }
        return ans.next;
    }
}
```