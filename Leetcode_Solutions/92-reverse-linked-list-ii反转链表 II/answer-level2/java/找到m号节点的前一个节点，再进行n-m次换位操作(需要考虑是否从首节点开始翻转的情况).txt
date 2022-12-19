

>    运行结果
 ![image.png](https://pic.leetcode-cn.com/38ab7dbacee52219d82985ccaf557f142534489c40737e8df80c7a47d280692c-image.png)



>

##### 代码部分 :
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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode tail = head;  // tail 记录首个需要翻转的节点
        ListNode pre = head;   // pre 记录首个需要翻转的节点的前一个节点

        for(int i=1; i<m; ++i) // 用 pre 记录翻转序列的前一个节点, tail 记录翻转序列的头一个节点
        {
            pre = tail;
            tail = tail.next;
        }

        n -= m; // 新的 n 记录需要翻转的次数
        ListNode sub_head = tail;  // 记录需翻转的字串的头节点

        while(n-- != 0){ // 翻转子串
            ListNode h = tail.next;
            tail.next = h.next;
            h.next = sub_head;
            sub_head = h;
            if(m != 1) // 若不是从第一个节点就开始翻转,则进行子串头节点的拼接操作
                pre.next = sub_head;
        }

        if(m != 1) // 若不是从首节点开始翻转,直接返回原头结点
            return head;
        return sub_head; // 否则表示从首节点开始翻转,返回新的头结点
    }
}
```
