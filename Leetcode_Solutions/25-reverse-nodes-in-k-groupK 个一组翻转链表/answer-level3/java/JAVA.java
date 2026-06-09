### 解题思路
利用递归
每k个数可以看作是链表的倒序，不停递归 直到剩余的结点不足k为止

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
        ListNode pHead = new ListNode(0);
        pHead.next = head;
        ListNode index = pHead;
        reverse(index,k);
        return pHead.next;
    }
    
    public void reverse(ListNode node, int length){
        ListNode p1=node;
        ListNode p2;
        int i;
        for(i=0;i<length;i++){
            p1=p1.next;
            if(p1==null) break;
        }
        if(i<length) return;
        else{
            p1=node.next;
            for(i=0;i<length-1;i++){
                p2=p1.next;
                p1.next=p2.next;
                p2.next=node.next;
                node.next=p2;
            }
            reverse(p1,length);
        }
    }
}
```