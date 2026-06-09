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
    public ListNode reverseBetween(ListNode head, int m, int n) {
       ListNode dummy = new ListNode(0);
       dummy.next=head;
       ListNode p = dummy;
       ListNode q = dummy.next;
       int i=1;
       while(i<m){
           p=p.next;
           q=q.next;
           i++;
       }
       while(i<n){
           ListNode tmp =q.next;
           q.next=q.next.next;
           tmp.next=p.next;
           p.next=tmp;
           i++;
       }
       return dummy.next;
    }
}
```