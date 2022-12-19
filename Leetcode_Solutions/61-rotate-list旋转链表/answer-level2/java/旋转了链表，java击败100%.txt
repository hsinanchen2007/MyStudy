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
  public ListNode rotateRight(ListNode head, int k) {
        if (head == null){
            return null;
        }
        if (k == 0){
            return head;
        }
        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;
        ListNode count = dummyHead.next;
        int size = 0;
        while(count != null){
            count = count.next;
            size++;
        }
        ListNode start = dummyHead.next;
        ListNode end = dummyHead;
        k = k%size;
        if (k == 0){
            return head;
        }
        int flag = size - k;
        ListNode p = dummyHead;
        while (flag > 0){
            p = p.next;
            flag--;
        }
        while (size>0){
            end = end.next;
            size--;
        }
        dummyHead.next = p.next;
        p.next = end.next;
        end.next = start;
        return dummyHead.next;
    }
}
```