### 解题思路


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
    public ListNode swapPairs(ListNode head) {
        if(head==null || head.next==null) return head;
        ListNode res = new ListNode(-1);//定义一个新的头指针
        ListNode pre = res;             //定义一个指针保存当前节点的前一个节点
        ListNode cur = head;            //遍历指针
        ListNode next = null;           //定义一个指针保存当前节点的下一个节点
        while(cur!=null){
            next = cur.next;//先保存下一个节点 待会会改变节点间的顺序
            if(next!=null) cur.next = next.next;// 1 指向 3
            else break;     //next==null说明最后只剩一个节点了，没必要反转了，直接break
            next.next = cur;//下一个节点指向当前节点 2->1
            pre.next = next;//前一个节点指向当前节点的下一个节点 -1->2
            pre = cur;      //由于是两两反转 直接跳到 -1->2->1->3->4 中的 1 而不是 2
            cur = cur.next; //由1跳到3
        }
        return res.next;
    }
}
```