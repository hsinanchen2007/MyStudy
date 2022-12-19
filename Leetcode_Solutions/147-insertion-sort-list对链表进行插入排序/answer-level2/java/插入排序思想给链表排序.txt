![2020040401.PNG](https://pic.leetcode-cn.com/09caa445e2aab0f5d4d5d877d88af53be4cd208ed10e9d61aa67433d8fabc733-2020040401.PNG)

### 解题思路
思路:
1.声明dummyHead 为哨兵结点, dummyHead的下一个结点为链表的实际头结点head
 
2.声明结点move, move指向非有序链表的第一个结点, 用来遍历非有序链表 

3.声明结点temp, 作为临时变量, 在将move结点插入到适合位置时使用到

4.声明结点end, 结点end是有序链表的最后一个结点

5.外层的while循环用来遍历非有序链表

6.内层的while循环用来遍历有序链表, 以找到move结点应该插入的正确位置

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
    public ListNode insertionSortList(ListNode head) {
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;
        ListNode temp = dummyHead;
        ListNode move = dummyHead;
        ListNode end = head;
        while(move.next!=null){//外层循环, 遍历非有序的链表
            if(end.val<=move.next.val){//当前的move结点的值与end结点的值是有序时, move和end往后移一位
                end = move.next;
                move = move.next;
            }else{
                head = dummyHead;//head用来遍历有序链表, 寻找当前move结点应该插入的位置
                //while循环找到当前move结点的正确位置
                while(head.next.val<move.next.val&&head.next!=move.next){
                    head = head.next;
                }
                //当while循环结束时, head结点的下一个结点就是当前move结点应该插入的位置
                //在正确位置将move结点插入
                temp = move.next;
                move.next = move.next.next;
                temp.next = head.next;
                head.next = temp;
            }
        }
        //最后返回哨兵dummyHead结点的下一个结点即可
        return dummyHead.next;
    }
}
```