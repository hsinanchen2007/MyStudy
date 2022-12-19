### 解题思路
此处撰写解题思路
定义一个指针cur，先让cur指针移动k步，然后再让head和cur同时移动，则当cur指针时，head指针指向的位置就为倒数第k个指针。
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
        if(head == null || k <= 0)
            return null;
        ListNode cur = head;
        for(int i = 0; i < k; i++){
            cur = cur.next;
        }
        while(cur != null){
            head = head.next;
            cur = cur.next;
        }
        return head;
    }
}
```