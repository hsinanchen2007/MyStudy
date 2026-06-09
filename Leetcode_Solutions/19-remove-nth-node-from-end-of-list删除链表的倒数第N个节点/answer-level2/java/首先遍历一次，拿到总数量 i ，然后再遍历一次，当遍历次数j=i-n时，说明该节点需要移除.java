思路: 首先遍历一次，拿到总数量 i ，然后再遍历一次，当遍历次数j=i-n时，说明该节点需要移除。

```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
        public ListNode removeNthFromEnd(ListNode head, int n) {
       //首先统计出数量
            int i = 0;
            ListNode currentNode = head;
            while (currentNode!=null){
                i++;
                currentNode = currentNode.next;
            }
            if(i == n){
                return head.next;
            }
            ListNode preNode = head;
            ListNode currentNode2 = head;
            int j = 0;
            while (currentNode2!=null){
                if(j+n==i){
                    preNode.next = currentNode2.next;
                    return head;
                }
                preNode = currentNode2;
                currentNode2 = currentNode2.next;
                j++;
            }
            return null;
        }
    
}
```