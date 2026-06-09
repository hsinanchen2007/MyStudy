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
        ListNode p1=head;
        ListNode p2=head;
        while(p1!=null){
            p1=p1.next;
            if(k<1){
                p2=p2.next;
            }
            k--;
        }
        return p2;
    }
}
```