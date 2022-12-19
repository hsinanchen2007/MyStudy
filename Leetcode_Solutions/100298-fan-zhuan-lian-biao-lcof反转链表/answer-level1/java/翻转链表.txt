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

    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null) return head; //当前的头结点(不存储数据)或者下一个(第一个数据))为空的话没有必要翻转了；建表
        
        //命名规范有助于理解
        ListNode pre = head;//指针指向头结点

        ListNode cur = head.next;//当前的节点(第一个数据节点)

        ListNode next = null;//（cur）的后继节点

        while(cur != null){

            next = cur.next;//赋值,上面定义的cur的节点的后继节点
            cur.next = pre;//讲当前的节点的指向pre（第一次循环的时候执行的头结点  此时完成了第一个节点指向了头结点,循环退出后在处理头结点）
            pre = cur;//后移操作  将pre（上面pre指向的是head头结点） --> cur（当前节点） 执行完这个代码后pre指向到了cur节点
            cur = next;//cur节点指向了后一位 


            //如此循环 pre指向到最后一位

        }

        head.next = null;//将头结点的实行赋值为null
        head = pre;//此时的pre循环后变成原来的最后一个节点赋值即可
        return head;
        //如果还不明白画一下图就好了[]()
    }
}
