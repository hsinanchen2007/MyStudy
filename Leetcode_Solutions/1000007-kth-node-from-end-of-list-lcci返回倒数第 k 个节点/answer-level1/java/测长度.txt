### 解题思路
很朴实的想法

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
        int n=0;
        ListNode node=head;
        while(node!=null){
            n++;
            node=node.next;
        }
        for(int i=n-k;i>0;i--){
            head=head.next;
        }
        return head.val;
    }
}
```