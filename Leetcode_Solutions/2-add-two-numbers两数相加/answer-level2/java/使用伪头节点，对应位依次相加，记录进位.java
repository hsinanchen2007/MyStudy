>![image.png](https://pic.leetcode-cn.com/cb3e7cfea37ffc6e8ec68bab14693898327e8239fca9e9559994201756776d8a-image.png)
>
代码:

```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode DummyHead = new ListNode(0); // 初始化一个伪头结点
        ListNode pre = DummyHead; // 用 pre 记录要创建并赋值的节点的前一个节点
        int Carry = 0;  // 初始化进位
        while( l1 != null || l2 != null || Carry > 0) // 继续相加的条件是 链表对应位置中存在不为空的节点 或 有进位
        {
            int sum = ((l1 != null) ? l1.val : 0) + ((l2 != null) ? l2.val : 0) + Carry; //计算对应位的和(需要加上进位)
            Carry = sum / 10; // 记录下次相加的进位
            pre.next = new ListNode(sum % 10); // 创建并赋值下个节点
            pre = pre.next; // pre 移动到新创建的节点位置上,便于下一轮继续创建新节点

            /* 当节点不为空的时候,指向它的下一个节点(之前判断的是其后节点是否为空,导致超时,因为与while的条件不匹配) */
            if(l1 != null)
                l1 = l1.next;
            if(l2 != null)
                l2 = l2.next;
        }
        return DummyHead.next; // 返回有数据的第一个节点,也就是伪节点的下一个节点
    }
}
```