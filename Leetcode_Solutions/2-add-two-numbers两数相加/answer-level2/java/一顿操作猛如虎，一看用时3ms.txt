### 解题思路
构造虚节点。
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        boolean flag = false;
        ListNode root = new ListNode(-1);
        ListNode temp = root;
        while(l1 != null || l2 != null){
            int x = l1 == null ? 0 : l1.val;
            int y = l2 == null ? 0 : l2.val;
            int sum = x + y;
            if(flag){
                sum++;
            }
            if(sum >= 10){
                flag = true;
                sum = sum % 10;
            }else{
                flag = false;
            }
            temp.next = new ListNode(sum);
            temp = temp.next;
            l1 = l1 == null ? null : l1.next;
            l2 = l2 == null ? null : l2.next;
        }
        if(flag){
            temp.next = new ListNode(1);
        }
        return root.next;
    }
}
```