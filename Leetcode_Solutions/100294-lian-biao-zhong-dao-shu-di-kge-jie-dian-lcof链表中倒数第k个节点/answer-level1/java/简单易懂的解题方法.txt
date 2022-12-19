### 解题思路
1.求出链表长度len
2.利用循环，求倒数第k个结点(k从1开始），即是求正数len-k+1结点，因此若下标从0开始，设已知结点为头结点，只需要循环len-k次
  特殊情况有三种：A.空链表，直接返回null B.k>len,不存在此结点，直接返回null C.k==len,直接返回第一个结点
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
    public ListNode getKthFromEnd(ListNode head, int k) {
        if(head==null){
        return null;
        }
        int len=countlen(head);
        if(k>len){
            return null;
        }
        if(k==len){
            return head;
        }
        ListNode cur=head;
        for(int i=0;i<len-k;i++){
            cur=cur.next;
        }
        return cur;
    }
    public int countlen(ListNode head){
        ListNode cur=head;
        int count=0;
        while(cur!=null){
            cur=cur.next;
            count++;
        }
        return count;
    }
}
```
结语：小白，如有不足请多指教。