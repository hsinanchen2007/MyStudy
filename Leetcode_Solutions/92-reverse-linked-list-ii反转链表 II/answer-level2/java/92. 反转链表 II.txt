### 解题思路
执行用时 :0 ms, 在所有 Java 提交中击败了 100.00% 的用户


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
    public ListNode reverseBetween(ListNode head, int m, int n) {

        if(m == n) return head;  // m 等于 n 不用逆置链表，直接返回；

        ListNode p = new ListNode(0);  //加头结点；
        p.next = head;

        ListNode first = p, second = p.next;  // first 指针最终指向链表（含头结点） m-1 位置，second 最终指向链表 n 位置；
        ListNode tail = null;                 // tail 指针最终指向 n-1 位置；
        
        for(int i=0; i<n; i++){              // 逆置链表

            if(i<m-1){
                first = first.next;
                second = second.next;
            }
            else {
                if(i==m-1){
                    first.next = null;
                    tail = second;
                }

                head = second;
                second = second.next;
                head.next = first.next;
                first.next = head;
            }
        }
        tail.next = second;      // 连接链表

        return p.next;
    }
}
```