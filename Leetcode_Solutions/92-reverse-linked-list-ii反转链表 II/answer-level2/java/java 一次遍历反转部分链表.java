### 解题思路
**解题步骤**
假设需要反转的部分是从 from 到 to
1. 判断 1 <= from <= to <= N, 如果不满足直接返回头节点
2. 找到第 from -1 个节点 fpre 和 to+1 个节点 tpos。fpre就是反转部分的前一个节点， tpos就是反转部分的后一个节点，把这两个节点之间的链表先反转，然后在接上这两个节点
3. 如果 fpre是 null, 说明反转是从头节点开始的。则返回新的头节点。否则返回原始链表的头节点

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
    //反转部分单向链表
    public ListNode reverseBetween(ListNode head, int m, int n){ // m -> from n-> to 
        int len = 0;// 这个变量用来记录移动的位置，并且获得链表的总长度
        ListNode node1 = head;
        ListNode fpre = null; //反转起始点的前一个位置标记指针
        ListNode tpos = null; // 反转结束点后一个位置的标记指针
        while(node1 != null){
            len++;//自增往前移动
            fpre = (len == m - 1) ? node1 : fpre;
            tpos = (len == n + 1) ? node1 : tpos ; 
            node1 = node1.next;
        }
        if(m > n || m < 1 || n > len) return head;
        node1 = fpre == null ? head : fpre.next;
        ListNode node2 = node1.next; // 这里node1, node2是用于链表反转部分的两个指针
        node1.next = tpos;// 反转部分的头节点必然只想tpos
        ListNode next = null; //第三个辅助指针
        while(node2 != tpos){// 这两个指针向前移动反转的条件是 node2指针没有到达 tpos
            next = node2.next; // 分割
            node2.next = node1; //反转
            node1 = node2; // 前移 NOTE: 过了这里 node1 指针会指向 to 坐标的节点
            node2 = next; //前移 NOTE: 过了这里 node2 指针会指向 tpos,
        } 
        if(fpre != null){ // 如果不是从头节点开始反转(即从中间某个节点开始反转)。需要将fpre与反转结束后的node1接起来
            fpre.next = node1;
            return head;
        }
        return node1; // 如果反转是从头节点开始那么就直接返回node1（此时node1就是待反转部分的最后一个节点。反转后就是整个链表的头节点）
    
    }
}
```