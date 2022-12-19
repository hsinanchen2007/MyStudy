### 解题思路
此处撰写解题思路
封装后两次翻转链表
执行用时 :
0 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
37.3 MB
, 在所有 Java 提交中击败了
14.29%
的用户
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
    public ListNode plusOne(ListNode head) {
        ListNode node = reverse(head);
        ListNode tmp = node;
        while (tmp.val == 9){
            tmp.val = 0;
            if (tmp.next == null){
                ListNode a = new ListNode(0);
                tmp.next = a;
            }
            tmp = tmp.next;
            
        }
        tmp.val += 1;
        return reverse(node);
        
    }
    private ListNode reverse(ListNode head){
        ListNode pre = null;
        ListNode cur = head;
        ListNode tmp = null;
        while (cur != null){
            tmp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
}
```