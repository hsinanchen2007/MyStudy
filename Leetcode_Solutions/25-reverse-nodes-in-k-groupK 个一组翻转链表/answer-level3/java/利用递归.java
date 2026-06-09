### 解题思路
利用递归
先算出链表长度 如果k>len 直接return head
然后再进行倒转 倒转完分为两块了 再对没倒转的那块再进行倒转....递归.....
然后再合并回来
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

        ListNode p = head;
        ListNode pre = null;
        ListNode next ;
        int temp = k;
        int len = 0;
        while (p != null) {
            p = p.next;
            len++;
        }

        if (k > len){
            return head;
        }
        p = head;
        while (p!=null && k-->0){
            next = p.next;
            p.next= pre;
            pre = p;
            p = next;
        }
        head.next = reverseKGroup(p, temp);
        return pre;

    }


}
```