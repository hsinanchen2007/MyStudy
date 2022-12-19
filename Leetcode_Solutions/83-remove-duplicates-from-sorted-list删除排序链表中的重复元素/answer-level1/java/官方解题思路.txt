### 解题思路
官方解题思路，只用一个current节点而非两个pre和rear节点可以介绍额外的判空。
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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode current = head;
        while(current!=null&&current.next!=null){
            if(current.val==current.next.val){
                current.next = current.next.next;
            }else{
                current=current.next;
            }
        }
        return head;
    }
}
```