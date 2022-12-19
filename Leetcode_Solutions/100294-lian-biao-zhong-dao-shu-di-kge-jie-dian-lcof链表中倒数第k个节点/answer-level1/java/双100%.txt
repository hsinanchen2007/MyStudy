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
    public ListNode getKthFromEnd(ListNode head, int k) {
                int n =0;
                ListNode p = head;
                while(p.next!=null){
                    p = p.next;
                    n++;
                }
                int m = n-k+1;
               for(int i=0;i<m;i++){
                   head = head.next;
               }
                return head;

    }
}
```