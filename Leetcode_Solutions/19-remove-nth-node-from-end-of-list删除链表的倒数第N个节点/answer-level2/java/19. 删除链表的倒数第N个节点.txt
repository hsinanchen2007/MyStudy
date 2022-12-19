### 解题思路
设定双指针，两指针之间间隔N，当后一指针指向链表末尾的Null时，前指针对应next就是要删除的节点
![image.png](https://pic.leetcode-cn.com/825871a33c9cbd46fa8c3b967e89b919ac36155998c083ffbadc871bcd17d7a6-image.png)

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode q = head;
        ListNode p = head;
        for(int i=0;i<n;i++){
            if(q.next==null)return head.next;
            q = q.next;
        }
        q = q.next;
        while(q!=null){
            p = p.next;
            q = q.next;
        }
        //delete
        p.next = p.next.next;
        return head;
    }
}
```