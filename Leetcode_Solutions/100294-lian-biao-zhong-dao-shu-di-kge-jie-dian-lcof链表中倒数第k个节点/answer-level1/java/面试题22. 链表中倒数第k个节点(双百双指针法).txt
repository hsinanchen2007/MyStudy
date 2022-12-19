### 解题思路
有3个需要注意的点：
1.k>链表长时
2.链表为空或者k=0

### 双指针法
一次遍历即可，O(n)。我们经过分析可知道，先让第一个指针走k-1步，然后第二个和第一个指针再同时走，直到第一个指针指向末尾，此时第二个指针的位置就是倒数第k个
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
        if(head==null||k==0)return null;
        ListNode p1=head;
        ListNode p2=head;
        for(int i=0;i<k-1;i++){
            if(p1.next!=null){
                p1=p1.next;
            }else return null;
        }
        while(p1.next!=null){
            p1=p1.next;
            p2=p2.next;
        }
        return p2;
    }
}
```