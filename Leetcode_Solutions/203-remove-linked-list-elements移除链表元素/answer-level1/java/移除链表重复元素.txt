### 解题思路
方法：哨兵节点。时间复杂度：O(n)；空间复杂度：O(1)。
![链表.PNG](https://pic.leetcode-cn.com/74f7dbef96bf5d53a37b0f6c6352649856bfe7d71bbd2c743bc7f4b7ef1bcbcc-%E9%93%BE%E8%A1%A8.PNG)
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
    public ListNode removeElements(ListNode head, int val) {
        //方法：哨兵结点
        ListNode solider = new ListNode(-1);
        solider.next = head;

        ListNode prev = solider;
        ListNode curr = head;
        while(curr != null){
            if(curr.val == val){
                prev.next = curr.next;
            }else{
                prev = curr;
            }
            curr = curr.next;
        }

        return solider.next;
    }
}
```