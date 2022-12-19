借鉴了官方解题的思路。
这个解法主要是为了延续 翻转链表I 的变量风格，方便模板化记忆。
1. 添加辅助节点，便于处理 m = 1；由于添加了辅助节点 m++ n++
2. 几个基本的指针 curr 用于遍历；con 用于记录 m 节点的前一个节点；tail 当遍历到第m个节点时，这个节点就是新节点的尾部了
3. 两个基本的循环
4. 最后重新连接的时候，就不用再考虑特殊情况了
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
        if(head == null || m >= n){
           return head; 
        }
        
        //添加辅助节点-注意m和n都要增加1
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        m++; 
        n++;
        
        //初始化
        ListNode curr = dummy;
        ListNode con = dummy;
        ListNode tail = null;
        
        while(m>1){
           con = curr; 
           curr = curr.next; 
           m--; 
           n--;    
        }
        tail = curr;//m的位置即为新链表的尾部
        
        //翻转链表-样版代码
        ListNode pre = null;
        while(n>0){
           ListNode tempNext = curr.next; 
           curr.next = pre;
           pre = curr; 
           curr = tempNext; 
           n--; 
        }
        
        //重新连接-不用考虑特殊情况
        con.next = pre;
        tail.next = curr;
        
        return dummy.next;
    }
}
```
