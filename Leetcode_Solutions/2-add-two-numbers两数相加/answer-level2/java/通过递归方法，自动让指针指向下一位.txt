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

    int count = 0;
    int dir = 0;
    ListNode result = new ListNode(0);
    ListNode oldNode = new ListNode(0);
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if(l1 == null){
            l1 = new ListNode(0);
        }
        if(l2 == null){
            l2 = new ListNode(0);
        }
        ListNode newListNode = new ListNode(0);
        if(count == 0){
            result = newListNode;
        } else {
            oldNode.next = newListNode;
        }

        int a = l1 == null ? 0 : l1.val;
        int b = l2 == null ? 0 : l2.val;
        if(a+b+dir>=10) {
            newListNode.val = (a+b+dir)%10;
            dir = 1;
        } else {
            newListNode.val = a+b+dir;
            dir = 0;
        } 

        if(l1.next == null && l2.next == null){
            if(dir == 1) {
                newListNode.next = new ListNode(1);
            }
            return result;
        } else {
            count ++;
            oldNode = newListNode;
            addTwoNumbers(l1.next,l2.next);
        }

        return result;
    }
}
```