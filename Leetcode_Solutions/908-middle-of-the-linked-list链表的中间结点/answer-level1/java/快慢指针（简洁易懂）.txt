### 解题思路
此处撰写解题思路
对链表不熟悉，拿到题目感觉自己无从下手，于是在解题栏目中给力了启发，
   快慢指针，非常巧妙
1、先定义两个指针，初始值都为head;
2、快指针的运行速度是慢指针的2倍；
3、当快指针fast.next==null || fast == null,则证明慢指针已到达中间节点。

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
    public ListNode middleNode(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;
        while(fast !=null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
}
```