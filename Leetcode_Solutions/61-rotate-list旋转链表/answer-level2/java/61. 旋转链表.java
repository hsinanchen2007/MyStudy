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

        if(head == null || head.next == null || k == 0) return head;
        ListNode test = head;
        int count = 0;
        while(test != null){
            test = test.next;
            count++;
        }

        k = k % count;

        if(k == 0) return head;

        ListNode list = new ListNode(-1);
        list.next = head;
        ListNode right = list.next, left = list.next, temp;

        for(int i=0; i<k; i++){
            right = right.next;
        }

        while(right.next != null){
            left = left.next;
            right = right.next;
        }

        temp = left.next;

        right.next = head;
        list.next = temp;
        left.next = null;

        return list.next;
    }
}
```