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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode preA=head; //双指针
        ListNode preB=head;
        for (int i = 0; i < n; i++) {
            preB= preB.next;    //先让指针B向后移动n个节点,如果是查找倒数第n个节点,那就向后移动n-1个节点
        }
        if (preB==null) {       //为避免空指针异常(可能删除的是头节点),先判断一下
            return head.next;   
        }
        while (preB.next!=null) {   
            preA=preA.next;
            preB=preB.next;
        }
        if (n==1) {             //也是为了避免空指针异常,分情况讨论
            preA.next=null;
            return head;
        }else{
            preA.next=preA.next.next;
            return head;
        }
    }
}
```