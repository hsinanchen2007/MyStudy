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
    public ListNode middleNode(ListNode head) {
        int l = 0;
        ListNode c = head;
        while(c!=null){
            c = c.next;
            l++;
        }
        // ListNode b = head;
        int s = l/2;
        while(s>0){
            head = head.next;
            s--;
        }

        return head;
    }
}
```