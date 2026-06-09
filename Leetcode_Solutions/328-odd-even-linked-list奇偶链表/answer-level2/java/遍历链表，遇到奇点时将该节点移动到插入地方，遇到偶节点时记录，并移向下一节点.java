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
    public ListNode oddEvenList(ListNode head) {
        if (head == null){
            return null;
        }
        ListNode curr = head.next;
        ListNode insert = head;
        ListNode pre = null;
        ListNode flag = null;
        int count = 2;
        while(curr != null ){
            if (count % 2 == 0){
                flag = curr;
                curr = curr.next;
            }else{
                pre = curr;
                curr = curr.next;
                flag.next = curr;
                pre.next = insert.next;
                insert.next = pre;
                insert = pre;
            }
            count ++;
        }
        return head;
    }
}
```