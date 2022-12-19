![2020032701.PNG](https://pic.leetcode-cn.com/5a6040007259ba7dec5e49fb36f24d2236c8498e947ecc6d20c6a25e87f6c24a-2020032701.PNG)

### 解题思路
/*
 * 思路:
 * 
 * 1. 声明一个新的结点cur, cur结点的下一个结点指向实际链表的头结点head;
 * 
 * 2. 先从cur开始遍历, 寻找的实际链表中的第m个结点的前一个结点;
 * 
 * 3. 再反转实际链表中的第m个结点到第n个结点;
 * 
 * 4. 在反转链表段(实际链表的第m个结点到第n个结点) 时, 声明结点node总是指向需要反转的链表段的头结点;
 * 
 * 5. 将链表的最终头结点返回:1) 若m==1, 返回node; 2) 若m!=1, 则返回head.
 */

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
        ListNode cur = new ListNode(-1);
        cur.next = head;//声明哨兵结点
        int cnt = 0;
        //先遍历链表, 找到第m个结点的前一个结点
        while(cnt<m-1){
            cur = cur.next;
            cnt++;
        }
        ListNode newHead = cur.next;
        ListNode node = cur.next;
        ListNode temp;
        cnt = 0;
        //反转第m个结点到第n个结点之间的链表
        while(cnt<(n-m)){
            cnt++;
            temp = newHead.next;
            newHead.next = newHead.next.next;
            temp.next = node;
            node = temp;
            cur.next = node;
        }
        //返回链表的头结点
        if(m==1){
            return node;
        }
        return head;
    }
}
```