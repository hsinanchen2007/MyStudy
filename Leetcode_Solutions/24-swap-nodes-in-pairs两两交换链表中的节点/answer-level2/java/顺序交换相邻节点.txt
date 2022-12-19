### 解题思路
每次交换相邻的两个节点，然后修改交换后两个节点的next节点即可。
一般情况： ……-> 1 -> 2 -> 3 -> 4 -> ……
交换后：   ……-> 2 -> 1 -> 4 -> 3 -> ……
比如要交换1和2两个节点，设cur为1，cur_next为2
因为交换后节点1（交换前的第1个节点）指向了节点4（交换前的第4个节点），并且
交换后的cur要指向3，cur_next要指向4，所以先**记录节点3，和4分别为t1和t2。**
交换cur和cur_next：
此时cur变为2 -> 3, cur_next变为了1-> 2
观察交换后的情况，将cur_next的next设为4（t2）,即cur_next变为1 -> 4,
cur自然指向cur_next，变为2 -> 1。
节点以及节点的next节点均设置完毕，继续交换后面相邻的两个节点3和4
cur = t1, cur_next = t2（**之前记录的t1和t2此时排上了用场**）。

注意如果最后剩下一个节点，那么不用交换cur和cur_next后面的节点，
此时需要修改cur_next.next指针指向原来cur_next，即之前**记录的t1**

**还有就是注意头结点的问题，头结点应该设置为原来的第二个节点，即head.next**

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
    public ListNode swapPairs(ListNode head) {
        // 如果有0或者1个节点，不用交换，直接返回
        if (head == null || head.next == null) {
            return head;
        }
        ListNode cur = head;
        ListNode root = cur.next;   // 新的头结点是第二个节点
        ListNode cur_next = cur.next;

        while (true) { 
            // 如果除了当前节点和其相邻节点之外，还有超过2个节点（一般情况），那么先记录一下后面的两个节点
            if (cur_next != null && cur_next.next != null && cur_next.next.next != null) {         
                ListNode t1 = cur_next.next;  // 记录当前节点和其相邻节点之后的两个节点
                ListNode t2 = cur_next.next.next;

                ListNode t = cur;  // 交换当前节点和其相邻节点
                cur = cur_next;
                cur_next = t;     

                cur_next.next = t2;  // 交换后，cur_next.next指向的是原来的第四个节点，
                cur.next = cur_next;  // cur.next自然指向cur_next

                cur = t1;  // 将刚才记录的两个节点t1和t2分别赋值给cur和cur_next
                cur_next = t2;
            } else {  //表示当前节点和其相邻节点之后没有节点或者只有一个节点，那么后面的节点就不用交换
                ListNode t = cur;
                cur = cur_next;
                cur_next = t;

                cur_next.next = cur.next;
                cur.next = cur_next;
                break;
            }
            
        }

        return root;
    }
}
```
![image.png](https://pic.leetcode-cn.com/cf5ed5dad89b22a20f2394b94630967912da83984205ca67f9b11a45d66c8b65-image.png)
