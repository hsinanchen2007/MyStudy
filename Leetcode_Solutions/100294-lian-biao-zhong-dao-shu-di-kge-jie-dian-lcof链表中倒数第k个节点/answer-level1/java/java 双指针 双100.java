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
    public ListNode getKthFromEnd(ListNode head, int k) {
        //慢指针
        ListNode slow=head;
        //快指针
        ListNode fast=head;
        int count=1;
        while(fast!=null){
            if(fast.next==null){
                //当快指针到达链表末尾时，慢指针就到达倒数k的节点位置
                return slow;
            }
            fast=fast.next;
            if(count==k){
                //当快指针和慢指针快k时，慢指针开始行动
                slow=slow.next;
            }else{
                count++;
            }
        }
        return slow;
    }
}
```