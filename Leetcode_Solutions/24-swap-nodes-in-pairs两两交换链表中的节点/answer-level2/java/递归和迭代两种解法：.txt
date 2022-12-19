### 解题思路
递归解法：
主要是关注最小的重复单元，不要想太深，不然容易晕。
关注三点：
1、返回值 2、重复单元中的操作 3、递归终止条件

迭代解法：
主要注意定义虚拟头结点的思想：这是链表问题 常用的技巧，主要用来避免讨论边界条件。

其中关于dummy.next的指向分析：因为pre也指向了dummy的地址，所以pre第一次的指向改变就是dummy的指向改变。之后pre变化，与dummy就没有关系了。

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
// class Solution {
//     public ListNode swapPairs(ListNode head) {
//         if(head == null || head.next == null){
//             return head;
//         }
//         ListNode pre = head;
//         ListNode cur = head.next;
        
//         pre.next = swapPairs(cur.next);
//         cur.next = pre;

//         return cur;
//     }
// }


class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode pre = dummy;

        while(head != null && head.next != null){
            ListNode firstNode = head;
            ListNode secondNode = head.next;
            pre.next = secondNode;
            firstNode.next = secondNode.next;
            secondNode.next = firstNode;

            pre = firstNode;
            head = firstNode.next;
        }
        return dummy.next;
    }
}
```