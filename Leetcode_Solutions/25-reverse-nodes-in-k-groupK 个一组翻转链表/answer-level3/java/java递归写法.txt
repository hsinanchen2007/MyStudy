### 解题思路
此处撰写解题思路
参考了网上的部分写法。思路主要是利用递归，每次对传入的元素head计算剩下的个数是否大于K，若大于，继续翻转，若不大于，则返回头节点。本思路内存消耗较大40.9MB，仅击败了5.01%的用户，方法仅供参考
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
        ListNode pre=null,cur=null,next=null;
        int n=k;
        cur=head;
        if(head==null) return head;
        int count=0;
        while(cur!=null){//对传入的新链表计算链表长度，看是否满足翻转要求
            count++;
            cur=cur.next;
        }
        cur=head;
        if(count<k) return head;
        while((cur!=null) &&(n-- >0)){//循环条件应注意在自减之后，n的值随之变化，之前没考虑这一点，只传入K，导致后面翻转的K全为0
            next=cur.next;
            cur.next=pre;
            pre=cur;
            cur=next;
        }
        head.next=reverseKGroup(next,k);
        return pre;
    }
}
```