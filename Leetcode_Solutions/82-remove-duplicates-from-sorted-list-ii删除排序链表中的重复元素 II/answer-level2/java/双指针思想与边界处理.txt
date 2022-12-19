## 思路分析
- 去重采用双指针思想；
-  考虑截断边界情况：（1,1），（1,1,1),  (1,2,2,2,3,4,4,4)

## 代码实现
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
        ListNode start = new ListNode(0);
        start.next = head;
        ListNode p = start.next, pre = start;
        int val = 0;
        while(p!=null&&p.next!=null){
            if(p.val!=p.next.val){
                if(pre.next!=p){
                    pre.next =p.next;
                }else{
                    pre.next = p;
                    pre=pre.next;
                }
            }else{
                // 记录当前重复的值
                val = p.val;
            }
            p = p.next;
        }
        
        if(p!=pre.next){
            if(val!=p.val){
                pre.next=p;                 
            }else{
                pre.next=null;                 
            }
        }         
        return start.next;
    }
}
```