### 解题思路
1、先将链表按照中点分为左右两个链表，再分别针对左右链表进行排序
       寻找链表的中点的方法可以用快慢指针的方法,如下所示:
        ListNode slow = head,ListNode fast = head.next;
       //这里的寻找中点的方法 不用很精确，只用保证只有两个元素的链表，可以斩断即可。
        //a->b
        while(fast!=null && fast.next!=null){
            slow = slow.next;
             fast = fast.next.next;
        }
       //记下中点
       ListNode tmp = slow.next;
       //将链表斩断
       slow.next = null;
      ListNode left = sortList(head);
       ListNode right = sortList(tmp);
2、将排序后的两个链表进行合并。
       //这里利用一个空节点
       ListNode h0  = new ListNode(0);
       ListNode h = h0;
       while(left!=null&&right!=null){
            if(left.val<=right.val){
                 h.next =left;
                 left = left.next;
            }else{
               h.next = right;
               right = right.next;
           }
          h = h.next;
      }
      h.next = left!=null?left:right;
3、最后将空节点的下一个元素h0.next返回。

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

     public ListNode sortList(ListNode head) {
           if(head==null||head.next==null){
            return head;
        }
        ListNode slow = head,fast = head.next;
        while(fast!=null&&fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode tmp = slow.next;
        slow.next = null;
        ListNode left = sortList(head);
        ListNode right = sortList(tmp);
        ListNode h = new ListNode(0);
        ListNode h0 = h;
        while(left!=null && right!=null){
            if(left.val<=right.val){
                h.next = left;
                left = left.next;
            }else{
                h.next = right;
                right= right.next;
            }
            h = h.next;
        }
        h.next = left!=null?left:right;
        return h0.next;
    }
}
```