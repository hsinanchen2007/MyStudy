### 解题思路
我们可以申请两个指针，第一个指针叫 pre，最初是指向 null 的。
第二个指针 cur 指向 head，然后不断遍历 cur。
每次迭代到 cur，都将 cur 的 next 指向 pre，然后 pre 和 cur 前进一位。
都迭代完了(cur 变成 null 了)，pre 就是最后一个节点。


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
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;
        ListNode temp = null;
        //以实际循环前两次为例子进行解析：{1,2,3,4,5}
        // --1-- curr val:1 next: ->2
        //--2-- curr val: 2 netx：-> 3
        while ( curr != null) {
            // temp 临时存储下一个元素信息
            //--1--temp val:2 next: ->3
            //--2 -- temp val:3 next: ->4
            temp = curr.next;
            //完成 curr next指向 prev （已反转链表）
            // --1-- curr val:1 next:null （完成反转）
            //--2-- curr val:2 next: -> 1 (完成反转)
            curr.next = prev;
            // prev 实现后移 
            //--1-- prev val:1 next:null (prev next为null 已经被独立保存)
            //--2-- prev val:2 next: -> 1
            prev = curr;
            //curr 实现后移
            //--1-- curr val: 2 netx：-> 3 
            //--2-- curr val:3 next: ->4
            curr = temp;
        }
        return prev;

    }
}
```