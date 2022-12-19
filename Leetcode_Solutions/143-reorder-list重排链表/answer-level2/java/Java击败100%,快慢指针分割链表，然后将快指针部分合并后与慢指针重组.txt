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
     public void reorderList(ListNode head) {
       if (head == null || head.next == null){
            return;
        }
        ListNode slow = head;
        ListNode fast = head.next;
        while(fast != null && fast.next != null) {
            fast = fast.next.next;
            head = head.next;
        }
        fast = head.next;
        head.next = null;
        ListNode reverfast = null;
        while (fast != null){
            ListNode next = fast.next;
            fast.next = reverfast;
            reverfast = fast;
            fast = next;
        }
        //这里得到了反转后的reverfast 和 原本分割好的 slow
        //将他们合并
        ListNode res = new ListNode(0);
        ListNode cur = res;
        while(slow != null && reverfast !=null){
            cur.next = slow;
            slow = slow.next;
            cur = cur.next;
            cur.next = reverfast;
            reverfast = reverfast.next;
            cur = cur.next;
        }
        cur.next = slow == null ? reverfast : slow;
        head = res.next;//结果
    }
}
```