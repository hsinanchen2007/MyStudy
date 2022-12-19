### 解题思路
和两两交换一个思路,每次做翻转，最后如果不足K就再翻转一遍

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
        if(head==null)
            return null;
        int t = 0;
        ListNode pre = null;
        ListNode cur = head;
        while(cur!=null&&t<k){
            ListNode next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
            ++t;
        }
        if(t < k){//再翻转回来
            cur = pre;
            pre = null;
            while(cur!=null){
                ListNode next = cur.next;
                cur.next = pre;
                pre = cur;
                cur = next;
            }
            return pre;            
        }
        head.next = reverseKGroup(cur,k);//递归翻转后K个
        return pre;

    }
}
```