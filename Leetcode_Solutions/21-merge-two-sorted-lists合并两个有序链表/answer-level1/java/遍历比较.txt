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
// 遍历两个链表，每次取出链表第一个元素进行比较，将较小的值添加到新链表；获取元素的链表重新赋值为next
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
   // 第一步声明一个初始链表，
        ListNode result = new ListNode(-1);
        // 临时链表，用于暂存每一次遍历较小值
        ListNode prev = result;

        while(l1 != null && l2 != null){
            if(l1.val <= l2.val){
                // 将临时链表的next设置为较小的节点，并且l1需要重新赋值为l1.next
                prev.next = l1;
                l1 = l1.next;
            }else {
                prev.next = l2;
                l2 = l2.next;
            }

            // 每一次遍历结束后，临时节点需要重新赋值 保证遍历顺序
            prev =prev.next;
        }

        // l1和l2有一个链表先遍历完，说明另一个链表剩下的部分比  当前新链表的值都大，可以直接连接在一起
        prev.next = l1 != null ? l1 :l2;

        return result.next;
    }
}
```