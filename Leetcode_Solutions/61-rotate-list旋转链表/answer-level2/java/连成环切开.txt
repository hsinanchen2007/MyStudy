### 解题思路
此处撰写解题思路
第一次循环，找到链表的长度，并且把链表连成环，
第二次循环，找到要切开的地方，通过要移动的次数和链表的长度，很容易判断出切点。
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
        if(head==null) return null;
        int num=1;
        ListNode p = head;
        ListNode q = head;
        while(p.next!=null){
            num++;
            p = p.next;
        }
        p.next = head;
        k = k%num;
        for(int i=1;i<num-k;i++){
            q = q.next;
        }
        ListNode l = q.next;
        q.next = null;
        return l;
    }
}
```