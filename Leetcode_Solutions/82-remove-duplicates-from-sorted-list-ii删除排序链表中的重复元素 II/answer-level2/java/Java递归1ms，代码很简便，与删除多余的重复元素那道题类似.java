### 解题思路
如果元素重复了就一直向后走，如果不重复就将当前指针指向下一个递归函数。对递归函数我的理解就是只处理当前的情况，其他的情况假设递归函数以及处理完毕。就这一句话至少一般的递归函数很快就能写出来。

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
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null || head.next == null)
           return head;
       ListNode next = head.next; //下一个元素
       if(next.val == head.val){
           while(next != null && next.val == head.val)
               next = next.next;
           return deleteDuplicates(next);//因为要将重复的都删了，所以直接返回递归函数
       }else{
           head.next = deleteDuplicates(head.next);//如果不重复就将当前节点指向递归函数
           return head;
       }
    }
}
```