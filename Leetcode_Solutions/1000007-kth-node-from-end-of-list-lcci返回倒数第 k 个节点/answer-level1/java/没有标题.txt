### 解题思路
先求出链表的长度，再循环到指定位置得到值并返回。本以为我这个方式效率会很差，没想到是双百

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
    public int kthToLast(ListNode head, int k) {
        int len = 0;
        ListNode tail = head;
        while(tail != null){
            tail = tail.next;
            len++;
        }
        for (int i = 0; i < len - k; i++) {
            if (i == len - k -1){
                head.val = head.next.val;
                head.next = head.next.next;
            }else{
                head = head.next;
            }
        }
        return head.val;
    }
}
```