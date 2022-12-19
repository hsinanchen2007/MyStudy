### 解题思路
翻转后，输出第k个

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
        
        ListNode p = null;
        ListNode q = head;
        ListNode temp = null;
        while(q!=null){
            temp = q.next;
            q.next = p;

            p = q;
            q = temp;
        }
        for(int i = 0;i<k-1;i++)
            p = p.next;
        return p.val;
    }
}
```