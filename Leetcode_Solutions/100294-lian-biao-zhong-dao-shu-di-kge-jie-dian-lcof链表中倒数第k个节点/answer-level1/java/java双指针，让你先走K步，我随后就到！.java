### 解题思路
双指针，第一个指针走k步，两个指针再一起走，当第一个指针走到末尾的时候，第二个指针所在的位置就是倒数第K个结点。

常见思路，记得判断当链表没有k个元素的情况！

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
        ListNode start = head;
        ListNode second = head;

        while(k>0 && start!=null){
            start = start.next;
            k--;
        }
        //如果没有K个节点则直接返回false
        if(k>0){
            return null;
        }
        while(start!=null){
            start = start.next;
            second = second.next;
        }
        return second;
    }
}
```