### 解题思路
遍历累加求解

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
    public int getDecimalValue(ListNode head) {
       if(head==null){
           return 0;
       }
       ListNode node=head;
       int ans=0;
       while(node!=null){
           ans=ans<<1;
           ans+=node.val;
           node=node.next;
       }
       return ans;
    }
}
```