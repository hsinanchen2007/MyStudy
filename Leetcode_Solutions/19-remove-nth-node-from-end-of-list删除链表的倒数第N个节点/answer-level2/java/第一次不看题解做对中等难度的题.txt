### 解题思路
此处撰写解题思路

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int l = 0;//先计算链表的长度
        ListNode cur = head;
        while(cur!=null){
            l++;
            cur = cur.next;
        }
        cur = head;
        int index = 0;
        int left = l+1-n;//正数的第几个数
        ListNode pre = null;
        while(cur!=null){
            index++;
            if(index==left){
                if(pre!=null){
                    pre.next = cur.next;
                }else{
                    
                    System.out.println(cur.val);
                    head = head.next;
                }
            }else{
                pre = cur;
            }
             if(cur!=null){
                 cur = cur.next;
             }
        }
        return head;
    }
}
```