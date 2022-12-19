### 解题思路
这道题目是[环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)的拓展,需要分两步来做.
第一步,就是环形链表的思路,先判断其是否有换,使用快慢指针,进行循环即可.
一开始快慢指针都指向head节点,然后接下来每次快指针前进2个节点,慢指针前进1个节点长度,如果有环的话,快指针一定会追上慢指针(可以类比三千米跑步比赛的时候,跑得快的同学往往要追上跑得慢的同学好几圈.😂),这样的话,就可以进行判断,如果快慢指针在某刻相等了,那么就是有环的,如果快指针指向了null,那么就说明无环.
通过第一步,可以确认是否有环,如果无环返回null,如果有环则开启第二部.
第二步,既然确认了是有环的存在,就要判断入环的第一个节点在何处.
首先确定快慢指针相遇的节点,我们可以让这个节点和头节点的指针同时移动,当二者相遇的时候就是入环的第一个节点了.
为什么会这样呢?
我们可以设环外节点为x,环内节点为y,通过第一步,可以知道,最终快慢指针是相遇了的,也就是说快指针要比慢指针多走ny步(n是圈数,快指针要比慢指针多跑n圈才追得上),而快指针始终走的距离始终就是慢指针的2倍.
可以得出公式  
fast(快指针) = 2slow(慢指针)
fast = slow + ny
则通过上述公式运算得到:
slow = ny
从头节点到第一个环节点的路程则是:
k = x + ny
由此可见,最终相遇节点只需要再往前走x步就可以确定第一个环节点位置.
不过并不知道x真正的是等于多少,可以让头节点指针和相遇节点指针同时向前移动,移动到二者相遇的位置就可以确定了.因为头节点指针走x步到入环节点,而相遇节点指针也是走x步到入环节点.
### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        //分两次求解
        //第一次求得是否有环
        //第二次求得入环节点
        ListNode fast = head;
        ListNode slow = head;
        while(true)
        {
            if(fast == null || fast.next == null)
            {
                return null;
            }
            fast = fast.next.next;
            slow = slow.next;
            if(fast == slow)
            {
                break;
            }
        }
        while(head!=slow)
        {
            head = head.next;
            slow = slow.next;
        }
        return head;
    }
}
```