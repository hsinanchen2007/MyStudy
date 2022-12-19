### 解题思路
仔细审题，仔细审题，莫急！！！

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
    public void deleteNode(ListNode node) {
        if(node==null){
            return;
        }
        ListNode nextnode=node.next;
        node.val=nextnode.val;
        node.next=nextnode.next;
        nextnode=null;
        
    }
}
```