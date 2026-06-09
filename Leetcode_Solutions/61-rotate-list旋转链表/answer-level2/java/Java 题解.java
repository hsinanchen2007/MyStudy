### 解题思路
把k对链表长度l取余，并取出链表后n-k个元素放在链表头。
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
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null){
            return null;
        }
        int l =0;
        ListNode idx = head;
        ListNode end = head;
        while(idx != null){
            l++;
            end = idx;
            idx = idx.next;
        }
        ListNode root = new ListNode(0);
        root.next = head;
        k = k % l;
        idx=head;
        for(int i = 0;i<l-k-1;i++){
            idx = idx.next;
        }
        if(k>0){
            root.next = idx.next;
            idx.next = null;
            end.next = head;
        }
        return root.next;

    }
}
```