![WechatIMG2.png](https://pic.leetcode-cn.com/55af55e76e8dfebd8facbad835bf8591f741341a999a157f33296f6e0a17edeb-WechatIMG2.png)
### 解题思路
我自己都没想到自己竟然用递归写出来了，并且一次提交就过了，刷了十来道链表题了，基本上都能用递归写出来，之前是很害怕，感觉递归好难写。就遵循一句话就可以用递归都写出来。这句话分为三步
1、找到终止条件
2、假设递归函数以及将后面的都完成了
3、处理第一个情况。
在这个题目中是这么处理
1、递归终止条件是head为null或者剩余节点数量小于k，那就直接返回
2、如果链表为1->2->3->4->5->null，k为2，那么假设3->4->5经过递归函数以及完成了翻转
3、接下来处理第一个情况，也就是1->2。
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
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null)
            return head;
        int m = k;
        ListNode cur = head;
        while(cur != null && --m >= 1)
            cur = cur.next;
        if(m >= 1)
            return head; //剩余节点不到k个，直接返回
        ListNode pre = reverseKGroup(cur.next, k);//假设3->4->5->null已经完成，已经变成4->3->5->null
        cur.next = null; //处理第一种情况，当前节点为2，要把2的next设置为null,作为终止条件
        cur = head;//从head也就是1开始处理
        //将head到cur进行翻转
        while(cur != null){
            ListNode  = cur.next; //记录下一个节点，也就是2
            cur.next = pre;//将1指向pre也就是前一个节点，也就是前面的4->3->5->null
            pre = cur;//将pre设置为1
            cur = next;//将cur设置为2
        }
        return pre;
    }
}
```