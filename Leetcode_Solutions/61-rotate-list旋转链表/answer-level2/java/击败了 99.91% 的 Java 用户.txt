### 思路
其实这个题目相当于找到倒数第 k 个节点，然后拼接即可。
难点就是 k > len 的时候怎么办，这里我们取余即可。

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
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null || k == 0 ) return head;
        ListNode cur = head, end = null, result = null;
        int len = 0;
        
        while(cur != null) {
            len++;
            k--;
            end = cur;
            cur = cur.next;
        }
        if(k > 0) k = k % len;
        if(k == 0) return head;

        cur  = head;
        if(k > 0) k = k - len;
        while(++k < 0) {
            cur = cur.next;
        }
        result = cur.next;
        cur.next = end.next;
        end.next = head;

        return result;
    }
}
```
