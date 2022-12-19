### 解题思路
双指针法，两个指针距离为k，同时向链表尾移动，第一个到达表尾后，第二个就是倒数第k的节点

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
        if(head == null || k == 0) return null;
        ListNode first = head, second = head;
        int size = 0;
        while(second != null){
            second = second.next;
            if(size == k){
                first = first.next;
            }else{
                 size++;
            }
        }
        return first;
    }
}
```